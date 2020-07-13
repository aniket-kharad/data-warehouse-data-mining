#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float compare(int n,char s1[n][20],char s2[n][20],int j,int k)
{
	char excellent[]="Excellent";
	char good[]="Good";
	char average[]="Average";
	char fair[]="Fair";
	char poor[]="Poor";
	float grade,g1,g2;
	if(strcmp(s1[j],excellent)==0)
		g1=1;
	else if(strcmp(s1[j],good)==0)
		g1=0.75;
	else if(strcmp(s1[j],average)==0)
		g1=0.5;
	else if(strcmp(s1[j],fair)==0)
		g1=0.25;
	else if(strcmp(s1[j],poor)==0)
		g1=0;
	
	if(strcmp(s2[k],excellent)==0)
		g2=1;
	else if (strcmp(s2[k],good)==0)
		g2=0.75;
	else if(strcmp(s2[k],average)==0)
		g2=0.5;
	else if(strcmp(s2[k],fair)==0)
		g2=0.25;
	else if(strcmp(s2[k],poor)==0)
		g2=0;
		
	grade=g1-g2;
	if(grade<0)
		grade=-grade;
	return grade;
}

void nominal(char arr[][6],int n,FILE *fw)
{
	float a[n][n];
	printf("\n###############################################################################################################################################################\n");
	printf("Elements of nominal type:\n");
	for(int j=0;	j<n;	j++)
		printf("%s \n",arr[j]);
	printf("\n");
	for(int j=0;	j<n;	j++)
	{
		for(int k=0;	k<n;	k++)
		{
			if(strcmp(arr[j],arr[k])==0)
			{
				a[j][k]=0;
			}
			else
				a[j][k]=1;
		}
	}
	
	printf("\nDissimilarity matrix of nominal data present in dataset:\n");
	for(int j=0;	j<n;	j++)
	{
		for(int k=0;	k<n;	k++)
		{
			printf("%.0f ",a[j][k]);
			fprintf(fw,"%.2f ",a[j][k]);
		}
		printf("\n");
		fprintf(fw,"\n");
	}
	printf("\n###############################################################################################################################################################\n");
	return ;
}
void  ordinal(char arr[][20],int n,FILE *fw)
{
	float a[n][n];
	int i=0;
	for(int j=0;	j<n;	j++)
	{
		for(int k=0;	k<n;	k++)
		{
			a[j][k]=compare(n,arr,arr,j,k);
		}
	}
	printf("\n###############################################################################################################################################################\n");
	printf("Elements of ordinal type:\n");
	for(int i=0;	i<n;	i++)
		printf("%s \n",arr[i]);
	printf("\nDissimilarity matrix of ordinal data present in dataset:\n");
	for(int j=0;	j<n;	j++)	
	{
		for(int k=0;	k<n;	k++)
		{
			printf("%.2f ",a[j][k]);
			fprintf(fw,"%.2f ",a[j][k]);
		}
		printf("\n");
		fprintf(fw,"\n");
	}
	printf("\n###############################################################################################################################################################\n");
	return ;

}
void numeric(float arr[],int n,FILE *fw)
{
	float a[n][n];
	FILE *fp;
	int i=0;
	int s,l;
		l=arr[0];
		s=arr[0];
		for(int j=0;	j<32;	j++)
		{
			if(arr[j]>l)
				l=arr[j];
			if(arr[j]<s)
				s=arr[j];	
		}
		printf("\n###############################################################################################################################################################\n");
		printf("Elements of numeric type: \n");
		for(int i=0;	i<n;	i++)
			printf("%.2f \n",arr[i]);
		printf("minimum = %d\n",s);
		printf("maximum = %d\n",l);
		for(int j=0;	j<32;	j++)
		{
			for(int k=0;	k<32;	k++)
			{
				a[j][k]=(abs(arr[j]-arr[k]))/(float)(l-s);
			}
		}
		printf("\nDissimilarity matrix of numeric data present in dataset:\n");
		for(int j=0;	j<32;	j++)
		{
			for(int k=0;	k<32;	k++)
			{	
				printf("%.2f ",a[j][k]);
				fprintf(fw,"%.2f ",a[j][k]);
			}
			printf("\n");
			fprintf(fw,"\n");
		}
		printf("\n###############################################################################################################################################################\n");
	return ;
}
int main()
{
	FILE *fp,*fw;
	int i=0,n;
	char s[20];	float Snum;
	char nomA[32][6],ordA[32][20];	float numA[32];
	int nomArr[32][32];	float ordArr[32][32],numArr[32][32];
	float Anom[32][32],Aord[32][32],Anum[32][32];
	float mixed[32][32];
	fp=fopen("mixed.txt","r");
	fw=fopen("matrix.txt","w");
	while(fscanf(fp,"%s",s)!=EOF)
	{
		strcpy(nomA[i],s);
		fscanf(fp,"%s",s);
		fscanf(fp,"%s",s);
		strcpy(ordA[i],s);
		fscanf(fp,"%s",s);
		fscanf(fp,"%f",&Snum);
		numA[i]=Snum;
		i++;
	}
	nominal(nomA,32,fw);
	ordinal(ordA,32,fw);
	numeric(numA,32,fw);
	fclose(fw);
	fw=fopen("matrix.txt","r");
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			fscanf(fw,"%f",&Anom[j][k]);	
		}
	}
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			fscanf(fw,"%f",&Aord[j][k]);
		}
	}
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			fscanf(fw,"%f",&Anum[j][k]);	
		}
	}
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			mixed[j][k]=(Anom[j][k]+Aord[j][k]+Anum[j][k])/(float)3.0;	
		}
	}
	printf("\n###############################################################################################################################################################\n");
	printf("Combined Dissimilarity matrix is :\n");
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			printf("%.2f ",mixed[j][k]);
		}
		printf("\n");
	}
	printf("\n###############################################################################################################################################################\n");
	float small=mixed[0][1];
	float large=mixed[0][1];
	int f1[32],f2[32];
	int e1[32],e2[32];
	i=0;
	int I=0;
	for(int j=0;	j<32-1;	j++)
	{
		for(int k=j+1;	k<32;	k++)
		{
			if(mixed[j][k]<small)
			{
				small= mixed[j][k];
			}
			if(mixed[j][k]>large)
			{
				large= mixed[j][k];
			}
		}
	}
	for(int j=0;	j<32-1;	j++)
	{
		for(int k=j+1;	k<32;	k++)
		{
			if(mixed[j][k]==small)
			{
				e1[i]=j;
				e2[i]=k;
				i++;
			}
			if(mixed[j][k]==large)
			{
				f1[I]=j;
				f2[I]=k;
				I++;
			}
		}
	}
	n=i;
	int n1=I;
	for(i=0;	i<n;	i++)
		printf("The most similar tuples are %d and %d with %.2f dissimilarily\n",e1[i]+1,e2[i]+1,small);
	for(i=0;	i<n1;	i++)
		printf("The most dissimilar tuples are %d and %d with %.2f dissimilarily\n",f1[i]+1,f2[i]+1,large);	
	return 0;	
}












