/*#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	char s[5];
	char arr[32][6];
	int a[32][32],i=0;
	fp=fopen("nominal.txt","r");
	while(fscanf(fp,"%s ",s)!=EOF)
	{
		strcpy(arr[i],s);
		i++;
	}
	for(int j=0;	j<32;	j++)
		printf("%s ",arr[j]);
	printf("\n");
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			if(strcmp(arr[j],arr[k])==0)
			{
				a[j][k]=0;
			}
			else
				a[j][k]=1;
		}
	}
	for(int j=0;	j<32;	j++)
	{
		for(int k=0;	k<32;	k++)
		{
			printf("%d ",a[j][k]);
		}
		printf("\n");
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i=0;
	char ss[6];
	int s,l,n;
	printf("Enter the number of columns containing nominal attributes:\n");
	scanf("%d",&n);
	char arr[n][32][6];
	int a[32][32][n];
	fp=fopen("nominal.txt","r");
	while(fscanf(fp,"%s ",ss)!=EOF)
	{
		
		strcpy(arr[0][i],ss);
		for(int p=1;	p<n;	p++)
		{
			fscanf(fp,"%s ",ss);
			strcmp(arr[p][i],ss);
		}
		i++;
	}
	for(int b=0;	b<n;	b++)
	{
		for(int j=0;	j<32;	j++)
		{
			for(int k=0;	k<32;	k++)
			{
				if(strcmp(arr[b][j],arr[b][k])==0)
				{
					a[j][k][b]=0;
				}
				else
					a[j][k][b]=1;
			}
		}
		for(int j=0;	j<32;	j++)	
		{
			for(int k=0;	k<32;	k++)
			{
				printf("%d ",a[j][k][b]);
			}
			printf("\n");
		}
	printf("\n");
	}
	return 0;
}
