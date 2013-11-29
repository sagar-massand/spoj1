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

#define mod 1000000007

#define inf -1400000000

class node
{
public:
	int left;
	int right;
	int sum;
	int max;
	void initialize()
	{
		left=inf;
		right=inf;
		sum=inf;
		max=inf;
	}
	void ini(int a)
	{
		left=a;
		right=a;
		sum=a;
		max=a;
	}
};
int max1(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
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
void build(node *final,int *num,int x,int start, int end)
{
	int temp,mid;
	if(start==end)
	{
		final[x].ini(num[start]);
	/*	final[x].left=num[start];
		final[x].right=num[start];
		final[x].sum=num[start];
		final[x].max=num[start];
	*/
	}
	else
	{
		mid=(start+end)/2;
		build(final,num,2*x,start,mid);
		build(final,num,2*x+1,mid+1,end);
		final[x].left=max1(final[2*x].left,final[2*x].sum+final[2*x+1].left);
		final[x].right=max1(final[2*x+1].right,final[2*x].right+final[2*x+1].sum);
		final[x].sum=(final[2*x].sum+final[2*x+1].sum);
		final[x].max=maxer(final[2*x].max,final[2*x+1].max,final[2*x].right+final[2*x+1].left);
	}
}
void update(node *final,int x,int st_x,int en_x,int numb,int value)
{
	int mid,temp;
	
	if(st_x==en_x)
	{
		final[x].ini(value);
	}
	else
	{
		mid=(st_x+en_x)/2;
		if(numb<=mid)
		{
			update(final,2*x,st_x,mid,numb,value);
		}
		else
		{
			update(final,2*x+1,mid+1,en_x,numb,value);
		}
		final[x].left=max1(final[2*x].left,final[2*x].sum+final[2*x+1].left);
		final[x].right=max1(final[2*x+1].right,final[2*x].right+final[2*x+1].sum);
		final[x].sum=(final[2*x].sum+final[2*x+1].sum);
		final[x].max=maxer(final[2*x].max,final[2*x+1].max,final[2*x].right+final[2*x+1].left);
	}
}
node query(node *final,int x,int st_x,int en_x,int start,int end)
{
	int mid,temp;
	node p1,p2,fin;
//	printf("I am in %d with start %d and end %d\n",x,st_x,en_x);
	if((st_x>=start)&&(en_x<=end))
	{
		return final[x];
	}
	else
	{
		mid=(st_x+en_x)/2;
		if((mid>=start)&&((mid+1)<=end))
		{
			p1=query(final,2*x,st_x,mid,start,end);
			p2=query(final,2*x+1,mid+1,en_x,start,end);
			if(p1.left==inf)
				fin.left=inf;
			else if((p1.sum==inf)||(p2.left==inf))
				fin.left=p1.left;
			else
				fin.left=max1(p1.left,p1.sum+p2.left);
			if(p2.right==inf)
				fin.right=inf;
			else if((p1.right==inf)||(p2.sum==inf))
				fin.right=p2.right;
			else	
				fin.right=max1(p2.right,p1.right+p2.sum);
			if((p1.sum==inf)||(p2.sum==inf))
				fin.sum=inf;
			fin.max=maxer(p1.max,p2.max,p1.right+p2.left);
			
		}
		else if(mid>=start)
		{
			p1=query(final,2*x,st_x,mid,start,end);
			//p2.initialize();
			fin.left=p1.left;
			fin.max=p1.max;
			fin.sum=inf;
			fin.right=inf;
		}
		else
		{
			//p1.initialize();
			p2=query(final,2*x+1,mid+1,en_x,start,end);
			fin.right=p2.right;
			fin.sum=inf;
			fin.left=inf;
			fin.max=p2.max;
		}
		
		return fin;
	}
}
int main()
{
	node final[132000];
	int num[60000];
	node ans;
	int n,i,j,k,m,start,end,temp;
	si(n)
	FOR(i,n)
	{
		si(num[i])
	}
	build(final,num,1,0,n-1);
	si(m)
	FOR(i,m)
	{
		si(temp)
		si(start)
		si(end)
		if(temp==1)
		{
			ans=query(final,1,0,n-1,start-1,end-1);
			pi(ans.max)
		}
		else
			update(final,1,0,n-1,start-1,end);
		
	}
}