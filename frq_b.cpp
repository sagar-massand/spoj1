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

#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	long long a,b,c,n,t,i,j,k;
	long long *prime,*prim;
	prim=(long long *)malloc(1000001*sizeof(long long));
	prime=(long long *)malloc(1000001*sizeof(long long));
	for(i=3;i<1000000;i+=2)
		prim[i]=1;
	prime[0]=2;
	k=1;
	for(i=3;i<1000;i+=2)
	{
		if(prim[i]==1)
		{
			prime[k]=i;
			k++;
			for(j=i*i;j<1000000;j+=(2*i))
			{
				prim[j]=0;
			}
		}
	}
	long long total;
	for(;i<1000000;i+=2)
	{
		if(prim[i]==1)
		{
			prime[k]=i;
			k++;
		}
	}
	total=k;
	sl(t)
	FOR(i,t)
	{
		long long ans=0,sum,num=k;
		sl(n)
		sl(k)
		for(a=3;a<=n;a++)
		{

		}
