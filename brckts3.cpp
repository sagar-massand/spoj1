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

#define inf 1000000007

#define max 10000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

void build(int *b,int s,int e,int *a,int x,int *f)
{
	if(s==e)
	{
		b[x]=a[s];
		f[x]=0;
	}
		
	else
	{
		int m=(s+e)/2;
		build(b,s,m,a,2*x,f);
		build(b,m+1,e,a,2*x+1,f);
		b[x]=min(b[2*x],b[2*x+1]);
		f[x]=0;
	}
//	printf("For x=%d, b[x]=%d,f[x]=%d,a[x]=%d\n",x,b[x],f[x],a[x]);
}

void update(int *b,int s,int e,int l,int r,int x,int u,int *f)
{
	
	if((s>=l)&&(e<=r))
	{
		f[x]+=u;
	//	printf("b[%d] is %d\n",x,b[x]+f[x]);
	}
	else
	{
		int m=(s+e)/2;
		f[2*x]+=f[x];
		f[2*x+1]+=f[x];
		f[x]=0;
		if(l<=m)
			update(b,s,m,l,r,2*x,u,f);
		if(r>m)
			update(b,m+1,e,l,r,2*x+1,u,f);
		b[x]=min(b[2*x+1]+f[2*x+1],b[2*x]+f[2*x]);
	//	printf("b[%d] is %d\n",x,b[x]);
	}

}

int query(int *b,int s,int e,int l,int r,int x,int *f)
{
	if((s>=l)&&(e<=r))
	{
		//printf("Return value of node %d is %d\n",x,(f[x]+b[x]));
		return (f[x]+b[x]);
	}
	else
	{
		int m=(s+e)/2;
		int t1=max,t2=max;
		f[2*x]+=f[x];
		f[2*x+1]+=f[x];
		f[x]=0;
		if(l<=m)
			t1=query(b,s,m,l,r,2*x,f);
		if(r>m)
			t2=query(b,m+1,e,l,r,2*x+1,f);
		//printf("Return value of node %d is %d\n",x,min(t1,t2));
		return min(t1,t2);
	}
}

int main()
{
	int i,j,k,n,m;
	
	FOR(j,10)
	{
		int a[30001],b[120000],f[120000];
		char ch[30001];
		int len,x,y,z;
		si(n)
		ss(ch)
		//len=strlen(ch);
		if(ch[0]=='(')	a[1]=1;
		else	a[1]=-1;
		FORi(i,1,n)
		{
			if(ch[i]=='(')
				a[i+1]=a[i]+1;
			else
				a[i+1]=a[i]-1;
		}
	//	FORi(i,1,n+1)
	//		pi(a[i])
		build(b,1,n,a,1,f);
		si(m)
		printf("Test %d:\n",j+1);
		FOR(i,m)
		{
			si(k)
			if(k==0)
			{
				x=query(b,1,n,1,n,1,f);
				y=query(b,1,n,n,n,1,f);
				if((x==0)&&(y==0))
					ps("YES")
				else
					ps("NO")
			}
			else
			{
				if(ch[k-1]=='(')
				{
					update(b,1,n,k,n,1,-2,f);
					ch[k-1]=')';
				}	
				else
				{
					update(b,1,n,k,n,1,2,f);
					ch[k-1]='(';
				}
					
			}
		}

	}
	return 0;
}