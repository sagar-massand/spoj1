#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

void swap(char *x,char *y)
{
	char temp;
	temp=*y;
	*y=*x;
	*x=temp;
}

void permute(char *s,int i,int len)
{
	int j,k;
	if(i==len)
		printf("%s\n",s);
	else
	{
		FORi(j,i,len+1)
		{
			if(i==j)
			{
				swap(s+i,s+j);
				permute(s,i+1,len);
				swap(s+i,s+j);
			}
			else
			{
				if(s[i]!=s[j])
				{
					swap(s+i,s+j);
					permute(s,i+1,len);
					swap(s+i,s+j);
				}
			}
		}	
	} 
}

int main()
{
	int len;
	char s[10];
	scanf("%s",s);
	len=strlen(s);
	permute(s,0,len-1);
}