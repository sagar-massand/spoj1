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

/*
Notable points:
1)no. of 1s in size L0 =[L0-b0,L0-a0]and[a1,b1]
2)no. of 0s=[a0,b0]

u cant put the minimum no. bcoz den, u cud take a 1 and derefore less dan min no.
If L0<L1,
min1=L0-b0;, max1=min(b1,L0-a0);
min0=max(a0,L1-b1), max0=b0
Suppose, u pick x,

*/
int main()
{
	int n,a0,b0,l0,a1,b1,l1;
	int i,j,k;
	int min1,max1,min0,max0;
	FOR(i,5)
	{
		si(n)
		si(a0)
		si(b0)
		si(l0)
		si(a1)
		si(b1)
		si(l1)
		if(l0<=l1)
		{
			min1=max(l0-b0,a1);
			max1=min(b1,l0-a0);
			min0=max(a0,l1-b1);
			max0=min(b0,l1-a1);
			if((min1<=max1)&&(min0<=max0))
			{
				FORi(j,min1,max1+1)
				{
					FORi(k,min0,max0+1)
					{

					}
				}
			}
			else
			{
				ps("-1")
			}
		}
		else
		{
			min1=max(l0-b0,a1);
			max1=min(b1,l0-a0);
			min0=max(a0,l1-b1);
			max0=min(b0,l1-a1);
			
		}



	}
	
}