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

class pos
{
public:
	double x;
	double y;

	void initialize(double a,double b)
	{
		x=a;
		y=b;
	}

};

bool compare(pos a,pos b)
{
	return (a.x<b.x);
}

int main()
{
	int n,i,j,k;
	double p,q;
	pos *a;
	si(n)
	while(n!=0)
	{
		a=(pos *)malloc(n*sizeof)
	}
}
