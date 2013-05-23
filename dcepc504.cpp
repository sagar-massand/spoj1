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
	long long n,t,k,c,i,j,temp;
	int a[10001],b[10001];
	sl(t)
	FOR(i,t)
	{
		sl(n)
		sl(k)
		temp=(k-1);
		a[n]=temp;
		for(j=n-1;j>0;j--)
		{
			temp/=2;
			a[j]=temp;
		}
		b[1]=0;
		FORi(j,2,n+1)
		{
			if(a[j]%2==0)
				b[j]=b[j-1];
			else
				b[j]=(!b[j-1]);
		}
		if(b[n]==0)
			ps("Male")
		else
			ps("Female")
		
	}
}