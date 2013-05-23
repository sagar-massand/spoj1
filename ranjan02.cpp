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

unsigned long long rec(unsigned long long n)
{
	if(n==1)
		return 1;
	else
		return (3*rec(n-1)+1);
}

int main()
{
	unsigned long long int a,b,c,t,n,i,j,k,ans;
	scanf("%llu",&t);
	FOR(i,t)
	{
		scanf("%llu",&n);
		ans=2*rec(n);
		printf("%llu\n",ans);
	}
	return 0;
}