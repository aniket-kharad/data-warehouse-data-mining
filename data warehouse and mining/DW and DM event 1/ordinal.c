#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
float compare(int n,char s1[][n][20],char s2[][n][20],int pass,int j,int k)
{
	char excellent[]="Excellent";
	char good[]="Good";
	char average[]="Average";
	char fair[]="Fair";
	char poor[]="Poor";
	float grade,g1,g2;
	if(strcmp(s1[pass][j],excellent)==0)
		g1=1;
	else if(strcmp(s1[pass][j],good)==0)
		g1=0.75;
	else if(strcmp(s1[pass][j],average)==0)
		g1=0.5;
	else if(strcmp(s1[pass][j],fair)==0)
		g1=0.25;
	else if(strcmp(s1[pass][j],poor)==0)
		g1=0;
	
	if(strcmp(s2[pass][k],excellent)==0)
		g2=1;
	else if (strcmp(s2[pass][k],good)==0)
		g2=0.75;
	else if(strcmp(s2[pass][k],average)==0)
		g2=0.5;
	else if(strcmp(s2[pass][k],fair)==0)
		g2=0.25;
	else if(strcmp(s2[pass][k],poor)==0)
		g2=0;
		
	grade=g1-g2;
	if(grade<0)
		grade=-grade;
	return grade;
}
int main()
{
	FILE *fp;
	int i=0;
	char ss[20];
	int s,l,n;
	printf("Enter the number of columns containing ordinal attributes:\n");
	scanf("%d",&n);
	char arr[n][32][20];
	float a[32][32][n];
	fp=fopen("ordinal.txt","r");
	while(fscanf(fp,"%s ",ss)!=EOF)
	{
		
		strcpy(arr[0][i],ss);
		for(int p=1;	p<n;	p++)
		{
			fscanf(fp,"%s ",ss);
			strcpy(arr[p][i],ss);
		}
		i++;
	}
	for(int b=0;	b<n;	b++)
	{
		for(int j=0;	j<32;	j++)
		{
			for(int k=0;	k<32;	k++)
			{
				a[j][k][b]=compare(32,arr,arr,b,j,k);
			}
		}
		for(int j=0;	j<32;	j++)	
		{
			for(int k=0;	k<32;	k++)
			{
				printf("%.2f ",a[j][k][b]);
			}
			printf("\n");
		}
	printf("\n");
	}
	return 0;
}

