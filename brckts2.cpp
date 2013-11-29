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

#define inf 1000000000

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
		
void build(int *flag,int *node,int *num,int *st,int *en,int x, int start, int end)
{
	int mid,i,j,k;
	st[x]=start;
	en[x]=end;
	if(start==end)
		node[x]=num[start];
	else
	{
		mid=(start+end)/2;
		build(flag,node,num,st,en,2*x,start,mid);
		build(flag,node,num,st,en,2*x+1,mid+1,end);
		node[x]=min(node[2*x],node[2*x+1]);
	}
}

int query(int *flag,int *node,int *st,int *en,int x,int start, int end)
{
	int mini,i,j,k;
	i=inf;
	j=inf;
	if((st[x]>=start)&&(en[x]<=end))
	{
	//	node[x]+=flag[x/2];
		return node[x];
	}
	else 
	{
	//	printf("Start and end are %d and %d respectively while x is %d\n",start,end,x);
		node[2*x]+=flag[x];
		node[2*x+1]+=flag[x];
	//	flag[x/2]=0;
		flag[2*x]+=flag[x];
		flag[2*x+1]+=flag[x];
		if(en[2*x]>=start)
			i=query(flag,node,st,en,2*x,start,end);
		if(st[2*x+1]<=end)
			j=query(flag,node,st,en,2*x+1,start,end);
		flag[x]=0;
		return min(i,j);
	}

}

void update1(int *flag,int *node,int *st,int *en,int x,int start, int end,int update)
{
	int mid,i,j,k;
	mid=(start+end)/2;
	flag[x]+=update;
	if((st[x]>=start)&&(en[x]<=end))
	{
		node[x]+=update;
	}
	else
	{

		if(en[2*x]>=start)
			update1(flag,node,st,en,2*x,start,end,flag[x]);
		if(st[2*x+1]<=end)
			update1(flag,node,st,en,2*x+1,start,end,flag[x]);
		node[x]=min(node[2*x],node[2*x+1]);
		flag[x]=0;
	}
}
void printer(int *flag,int *node,int *st,int *en,int x)
{
	if(st[x]==en[x])
		printf("Node %d contains value %d with start %d and end %d\n",x,node[x],st[x],en[x]);
	else
	{
		
		printer(flag,node,st,en,2*x);
		printer(flag,node,st,en,2*x+1);
		printf("Node %d contains value %d with start %d and end %d\n",x,node[x],st[x],en[x]);
	}
}
int main()
{
	int *flag,*node,*st,*en,*num;
	int t,i,j,k,n,q,temp,ans,a,b,c;
	char ch[40000];
	FOR(i,10)
	{
		si(n)
		ss(ch)
		//n=strn(ch);
		flag=(int *)malloc(4*n*sizeof(int));
		node=(int *)malloc(4*n*sizeof(int));
		st=(int *)malloc(4*n*sizeof(int));
		en=(int *)malloc(4*n*sizeof(int));
		num=(int *)malloc(n*sizeof(int));
		FOR(j,4*n)
		{
			flag[j]=0;
		}
		if(ch[0]=='(')
			num[0]=1;
		else
			num[0]=-1;
		FORi(j,1,n)
		{
			if(ch[j]=='(')
				num[j]=(num[j-1]+1);
			else
				num[j]=(num[j-1]-1);
		}
		build(flag,node,num,st,en,1,0,n-1);
	//	printer(flag,node,st,en,1);
		si(q)
		printf("Test %d:\n",i+1);
		FOR(j,q)
		{
			si(temp)
			if(temp==0)
			{
			//	printer(flag,node,st,en,1);
			//	ps("B4 1st query")
				a=query(flag,node,st,en,1,0,n-1);
			//	ps("After 1st query")
				b=query(flag,node,st,en,1,n-1,n-1);
			//	ps("After 2nd query")
				if((a==0)&&(b==0))
					ps("YES")
				else
					ps("NO")
			}
			else
			{
				if(ch[temp-1]==')')
				{
					update1(flag,node,st,en,1,temp-1,n-1,2);
					ch[temp-1]='(';
				}	
				else
				{
					update1(flag,node,st,en,1,temp-1,n-1,-2);
					ch[temp-1]=')';
				}
			}
		}
		free(flag);
		free(node);
		free(st);
		free(en);
		free(num);
	}
}
	
