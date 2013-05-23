#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
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

#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	long long *num[101];
	long long i,j,k,n,sum,mod=761238923;
	FOR(i,101)
	{
		num[i]=(long long *)malloc(101*sizeof(long long));
	}
	sl(n)
	/*FORi(i,1,101)
	{
		FORi(j,)
	}*/
	while(n!=0)
	{
		FORi(i,1,n+1)
		{
			FORi(j,0,n+1)
			{
				num[i][j]=0;
			}
		}
		num[1][0]=1;
		num[1][1]=1;
		for(i=2;i<n;i++)
		{
			sum=0;
			for(j=0;j<=i;j++)
			{
				sum+=num[i-1][j];
				sum%=mod;
				num[i][j]=sum;
			}
		}	
		//num[n][n]=0;
		FOR(i,n)
		{
			num[n][n]+=num[n-1][i];
			num[n][n]%=mod;
		}
		pl(num[n][n])
		sl(n)
	}
}