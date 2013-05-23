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
	long long t,i,j,k,n,num,sum,max,temp;
	sl(t)
	FORi(i,1,t+1)
	{
		sum=0;
		max=0;
		sl(n)
		FOR(j,n)
		{
			sl(num)
			sum+=num;
			if(sum<0)
			{
				temp=-1*sum;
				if(max<temp)
					max=temp;
			}
		}
		max++;
		printf("Scenario #%lld: %lld\n",i,max);
	}
	return 0;
}