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

long long query(long long *node,long long *flag,long long x,long long st_x,long long en_x,long long start,long long end)
{
//	printf("I am in x %lld with start %lld and end %lld with value %lld\n",x,st_x,en_x,node[x]);
	long long temp1=0,temp2=0,mid;
	if((st_x>=start)&&(en_x<=end))
	{
	//	printf("The value abt to be returned is %lld and I am in node %lld with start %lld and end %lld\n",node[x],x,st_x,en_x);
		return node[x];
	}	
	else
	{
	//	node[2*x]+=flag[x];
	//	node[2*x+1]+=flag[x];
		flag[2*x]+=flag[x];
		flag[2*x+1]+=flag[x];
		mid=(st_x+en_x)/2;
		node[2*x]+=((mid+1-st_x)*flag[x]);
		node[2*x+1]+=((en_x-mid)*flag[x]);
		flag[x]=0;
		if(mid>=start)
			temp1=query(node,flag,2*x,st_x,mid,start,end);
		if((mid+1)<=end)
			temp2=query(node,flag,2*x+1,mid+1,en_x,start,end);
		//printf("The value abt to be returned is %lld and I am in node %lld with start %lld and end %lld\n",temp1+temp2,x,st_x,en_x);
		//flag[x]=0;
		return (temp1+temp2);
		//return node[x];
	}
}

void update(long long *node,long long *flag,long long x,long long st_x,long long en_x,long long start,long long end,long long value)
{
//	printf("I am in node %lld with start %lld and end %lld and value %lld, and flag value %lld\n",x,st_x,en_x,node[x],flag[x]);
	long long mid,temp;
	//flag[x]+=value;
	if((st_x>=start)&&(en_x<=end))
	{
		node[x]+=((en_x+1-st_x)*value);
		flag[x]+=value;
	}
	else
	{
		mid=(st_x+en_x)/2;
		node[2*x]+=((mid+1-st_x)*flag[x]);
		flag[2*x]+=flag[x];
		node[2*x+1]+=((en_x-mid)*flag[x]);
		flag[2*x+1]+=flag[x];
		flag[x]=0;
		if(mid>=start)
			update(node,flag,2*x,st_x,mid,start,end,value);
		if((mid+1)<=end)
			update(node,flag,2*x+1,mid+1,en_x,start,end,value);
		node[x]=(node[2*x]+node[2*x+1]);
	//	flag[x]=0;
	}
//	printf("I am in node %lld with start %lld and end %lld and value %lld, and flag value %lld\n",x,st_x,en_x,node[x],flag[x]);
}
void printer(long long *node,long long *flag,long long x,long long start,long long end)
{
	int mid=(start+end)/2;
	printf("I am in node %lld with start %lld and end %lld and value %lld, and flag value %lld\n",x,start,end,node[x],flag[x]);
	if(start!=end)
	{
		printer(node,flag,2*x,start,mid);
		printer(node,flag,2*x+1,mid+1,end);
	}
	
}

int main()
{
	long long *num, *node, *flag;
	long long t,i,j,k,n,ans,m;
	long long temp,p,q,v;
	sl(t)
	FOR(i,t)
	{
		sl(n)
		sl(m)
		//num=(long long *)malloc(n*slzeof(long long));
		node=(long long *)malloc(4*n*sizeof(long long));
		flag=(long long *)malloc(4*n*sizeof(long long));
		FOR(j,4*n)
		{
			node[j]=0;
			flag[j]=0;
		}
		
		FOR(j,m)
		{
		//	printer(node,flag,1,0,n-1);
			sl(temp)
			if(temp==0)
			{
				scanf("%lld%lld%lld",&p,&q,&v);
				update(node,flag,1,0,n-1,p-1,q-1,v);
			}
			else
			{
				sl(p)
				sl(q)
				ans=query(node,flag,1,0,n-1,p-1,q-1);
				pl(ans)
			}
		}
		free(node);
		free(flag);
	}
}