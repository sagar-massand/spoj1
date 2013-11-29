#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
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

#define pb			push_back

#define alc(a,n)	a=(typeof(a))malloc(n*sizeof(typeof(*a)));

#define inf 1000000007

#define max 10000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

class node
{
	int l;
	int l_c;
	int r;
	int r_c;
	int m;
	int m_c;
	void ini(int a,int b,int c,int d,int e,int f)
	{
		l=a;
		l_c=b;
		r=c;
		r_c=d;
		m=e;
		m_c=f;
	}
};

void build(node *num,int *a,int s,int e,int x)
{
	if(s==e)
	{
		num[x].ini(a[s],1,a[s],1,a[s],1);
	}
	else
	{
		int m=(s+e)/2;
		build(num,a,s,m,2*x);
		build(num,a,m+1,e,2*x+1);	
		if(num[2*x].l==num[2*x].r)
		{
			
		}
	}
}

int main()
{
	int i,j,k,n,t,q;
	node *num;
	int *a;
	si(n)
	while(n!=0)	
	{
		si(q)
		alc(num,4*n);
		alc(a,n+1);
		FORi(i,1,n+1)
		{
			si(a[i])
		}
		build(num,a,1,n,1);
	}
}