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

long long min1(long long a,long long b)
{
	if(a<b)
		return a;
	else
		return b;
}

long long find_min(long long a,long long b,long long c)
{
	long long min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;

}

int main()
{
	long long a[20],d[20],b[20];
	long long i,j,k,t,n,acur,dcur,bcur,ans;
	sl(t)
	FOR(i,t)
	{
		FORi(j,1,20)
		{
			a[j]=0;
			d[j]=0;
			b[j]=0;
		}
		sl(n)
		sl(a[0])
		sl(d[0])
		sl(b[0])
		FORi(j,1,n)
		{
			sl(acur)
			sl(dcur)
			sl(bcur)
			a[j]=min1(b[j-1],d[j-1])+acur;
			d[j]=min1(a[j-1],b[j-1])+dcur;
			b[j]=min1(a[j-1],d[j-1])+bcur;
		}
		ans=find_min(a[n-1],b[n-1],d[n-1]);
		pl(ans)

	}
	return 0;
	
}