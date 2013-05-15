#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

int min(int a, int b,int c)
{
	int min=a;
	if(b<a)
		min=b;
	if(c<min)
		min=c;
	return min;

}

void init_num(int **num,int len1,int len2)
{
	int i,j;
	FOR(i,len1+1)
	{
		num[i][0]=i;
	}
	FOR(i,len2+1)
	{
		num[0][i]=i;
	}
}

int dist(char *ch1,char *ch2)
{
	int len1,len2,i,j,k;
	int **num;
	len1=strlen(ch1);
	len2=strlen(ch2);
	num=(int **)malloc((len1+1)*sizeof(int *));
	FOR(i,len1+1)
	{
		num[i]=(int *)malloc((len2+1)*sizeof(int));
	}
	init_num(num,len1,len2);
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(ch1[i-1]==ch2[j-1])
				num[i][j]=num[i-1][j-1];
			else
			{
				num[i][j]=min(num[i-1][j-1]+1,num[i][j-1]+1,num[i-1][j]+1);
			}
		}
	}
	return num[len1][len2];
}

int main()
{
	int t,i,j,k,n,len1,len2,a,b,c,ans;
	char ch1[5000],ch2[5000];
	int **num;
	si(t)
	FOR(i,t)
	{
		ss(ch1);
		
		ss(ch2)

		ans=dist(ch1,ch2);
		pi(ans)
	}
	return 0;
}