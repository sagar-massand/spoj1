#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

bool compare(long long a,long long b)
{
	return (a<b);
}

long long hcf(long long a,long long b)
{
	long long temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	temp=a%b;
	while(temp!=0)
	{
		a=b;
		b=temp;
		temp=a%b;
	}
	return b;
}


int main()
{
	long long n,i,j,k,sum,flag;
	long long a[4];
	sl(n);
	sl(a[0]);
	sl(a[1]);
	sl(a[2]);
	sl(a[3]);
	while(n!=0)
	{
		flag=0;
		sum=0;
		FOR(k,4)
		{
			sum+=a[k];
		}
		if((a[0]%n==0)&&(a[1]%n==0)&&(a[2]%n==0)&&(a[3]%n==0))
		{
			flag=1;
		}
		sort(a,a+4,compare);
		i=hcf(a[0],a[1]);
		j=hcf(a[2],a[3]);
		a[0]/=i;
		a[1]/=i;
		a[2]/=j;
		a[3]/=j;
		i=hcf(a[0],a[2]);
		j=hcf(a[1],a[3]);
		a[0]/=i;
		a[2]/=i;
		a[1]/=j;
		a[3]/=j;
/*		pl(a[0])
		pl(a[1])
		pl(a[2])
		pl(a[3])
*/		if((sum==n*n*n)&&((a[0]*a[3])==(a[1]*a[2]))&&(flag==1))
		{
			ps("Possible")
			flag=0;
		}
		else
		{
			ps("Impossible")
		}

		sl(n);
		sl(a[0]);
		sl(a[1]);
		sl(a[2]);
		sl(a[3]);
	}

	return 0;
}