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

long long comb(long long a, long long b)
{
	long long i,j,k,ans=1;
	if((b==0)||(b==a))
		return 1;
	else
	{
		i=2;
		if(b<a-b)
			b=a-b;
		for(j=b+1;j<=a;j++)
		{
			ans*=j;
			while(i<=a-b)
			{
				if(ans%i==0)
				{
					ans/=i;
					i++;
				}
			}
		}
		return ans;
	}


}

double calc(long long n,long long r)
{
	/* Coeff of x^r/6^n=ans
		coeff of  x^r=C(n+r-1,n-1)-C(n,1)C(n+r-7,n-1)+
	*/
	long long c1,c2;
	c1=comb(n+r-1,n-1);
	c2=1;
	
	for(i=1;(r-6*i)>=0;i++)
	{

	}

}

int main()
{
	long long a,b,c,i,j,k,n,t,r;
	long long den;
	double ans;

	sl(t)
	FOR(a,t)
	{
		sl(n)
		sl(k)
		r=k-n;
		ans=calc(n,r);
	}
}