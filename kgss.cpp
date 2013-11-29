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

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define inf -1000000007

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

class node
{
public:
	int max;
	int sum;
	void init(int a,int b)
	{
		max=a;
		sum=b;
	}
};

int maxer(int a,int b,int c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		else
			return c;
	}
	else
	{
		if(b>c)
			return b;
		else
			return c;
	}
}
int ma(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

void build(node *final,int *num,int x,int b,int e)
{
	int mid,i,j,k;
	if(b==e)
	{
		final[x].max=num[b];
		final[x].sum=num[b];
	}
	else
	{
		mid=(b+e)/2;
		build(final,num,2*x,b,mid);
		build(final,num,2*x+1,mid+1,e);
		final[x].sum=maxer(final[2*x].sum,final[2*x+1].sum,final[2*x].max+final[2*x+1].max);
		final[x].max=ma(final[2*x].max,final[2*x+1].max);
	//	printf("Current max is %d and sum is %d,current start and end is %d and %d\n",final[x].max,final[x].sum,b,e);
	}
}
node query(node *final,int *num,int x,int st,int en,int b,int e)
{
	int m;
	node i,j,k;
	i.init(0,0);
	j.init(0,0);
//	printf("Hello, start is %d,end is %d while b and e is %d and %d\n",st,en,b,e);
	if((st>=b)&&(en<=e))
	{
//		printf("Current max is %d and sum is %d,current start and end is %d and %d\n",final[x].max,final[x].sum,st,en);
		return final[x];
	}
	else
	{

		m=(st+en)/2;
		if(m>=b)
			i=query(final,num,2*x,st,m,b,e);
		if((m+1)<=e)
			j=query(final,num,2*x+1,m+1,en,b,e);
		k.sum=maxer(i.sum,j.sum,i.max+j.max);
		k.max=ma(i.max,j.max);
//		printf("Current max is %d and sum is %d,current start and end is %d and %d\n",k.max,k.sum,st,en);
		return k;
	}
}
void update(node *final,int *num,int x,int st,int en,int b,int val)
{
	int m;
	if(st==en)
	{
		final[x].max=val;
		final[x].sum=val;
	//	printf("Current max is %d and sum is %d,current start and end is %d and %d\n",final[x].max,final[x].sum,st,en);
	}
	else
	{
		m=(st+en)/2;
		if(m>=b)
		{
			update(final,num,2*x,st,m,b,val);
		}
		else
		{
			update(final,num,2*x+1,m+1,en,b,val);
		}
		final[x].sum=maxer(final[2*x].sum,final[2*x+1].sum,final[2*x].max+final[2*x+1].max);
		final[x].max=ma(final[2*x].max,final[2*x+1].max);

	//	printf("Current max is %d and sum is %d,current start and end is %d and %d\n",final[x].max,final[x].sum,st,en);
	}
}
void printer(node *final,int x,int b,int e)
{
	int m=(b+e)/2;
	printf("Current max is %d and sum is %d,current start and end is %d and %d\n",final[x].max,final[x].sum,b,e);
	if(b<e)
	{
		printer(final,2*x,b,m);
		printer(final,2*x+1,m+1,e);
	}
}

int main()
{
	int n,temp,i,j,k;
	si(n)
	int *num;
	node *final;
	final=(node *)malloc(4*n*sizeof(node));
	num=(int *)malloc((n+1)*sizeof(int));
	FOR(i,n)
	{
		si(num[i])
	}
	build(final,num,1,0,n-1);
	char ch;
	int q;
	si(q)
	FOR(i,q)
	{
		node ans;
		sc(ch)
		si(j)
		si(k)
		if(ch=='U')
		{
			update(final,num,1,0,n-1,j-1,k);
		}
		else
		{
			ans=query(final,num,1,0,n-1,j-1,k-1);
			pi(ans.sum)
		}
	//	printer(final,1,0,n-1);
	}

}