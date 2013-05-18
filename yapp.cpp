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

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define FORi(i,a,n)	for(i=a;i<n;i++)

long long power(long long a,long long b,long long mod)
{
	long long ans,fin;
	if(b>1)
	{
		fin=power(a,b/2,mod);
		if(b%2==1)
		{
			ans=(((fin*fin)%mod)*a);
			return (ans%mod);
		}
		else
		{
			ans=((fin*fin)%mod);
			return ans;
		}
	}
	else if(b==1)
		return a;
	else
		return 1;
}
int main()
{
	long long t,i,j,k,n,ans,mod=1000000007;
	sl(t)
	FOR(i,t)
	{
		sl(n)
		ans=power(2,n-1,mod);
		pl(ans)
	}
	return 0;
}