#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<time.h>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define pf(n)		printf("%lf\n",n);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define FORi(i,a,b)	for(i=a;i<b;i++)

int main()
{
	int x[3],y[3],t,count=0,i,j,k,num[3],temp;
	si(t)
	FOR(i,t)
	{
		FOR(j,3)
		{
			scanf("%d%d",&x[j],&y[j]);
			num[j]=0;
		}
		FOR(j,3)
		{
			num[j]=(((x[(j+1)%3]-x[j])*(x[(j+1)%3]-x[j]))+((y[(j+1)%3]-y[j])*(y[(j+1)%3]-y[j])));
		}	
		FOR(j,2)
		{
			FORi(k,j+1,3)
			{
				if(num[k]<num[j])
				{
					temp=num[k];
					num[k]=num[j];
					num[j]=temp;
				}
			}
		}
		if(num[0]+num[1]==num[2])
			count++;
	}
	pi(count)
}