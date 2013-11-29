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

long long find_gcd(long long a,long long b)
{
	long long temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	long long rem;
	rem=a%b;
	while(rem!=0)
	{
		a=b;
		b=rem;
		rem=a%b;
	}
	return b;
}

int main()
{
	long long n,i,j,k,gcd,total;
	long long *num;
	sl(n)
	num=(long long *)malloc(n*sizeof(long long));
	sl(num[0])
	sl(num[1])
	gcd=(num[1]-num[0]);
	FORi(i,2,n)
	{
		sl(num[i])
		gcd=find_gcd(gcd,num[i]-num[i-1]);
	}
	total=((num[n-1]-num[0])/gcd)+1;
	total-=n;
	pl(total)
	return 0;
}