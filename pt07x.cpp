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

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int count1;

class node
{
public:
	std::vector<int> adj;
	int visited;
	int num;
	int listed;
	int parent;
	void initialize(int a)
	{
		num=a;
		adj.clear();
		visited=0;
		listed=0;
		parent=0;
	}
};

void dfs(node *num,int p)
{
	//printf("Current p is %d while count1 is %d\n",p,count1);
	int i,j,k,temp;
	num[p].visited=1;
	FOR(i,num[p].adj.size())
	{
		temp=num[p].adj[i];
		if(num[temp].visited==0)
		{
			num[temp].parent=p;
			dfs(num,temp);
		}
	}
/*	if(p==7)
	{
		pi(num[8].listed)
	}
*/	FOR(i,num[p].adj.size())
	{
		temp=num[p].adj[i];
	//	pi(temp)
		if(temp!=num[p].parent)
		{
			if(num[temp].listed==0)
			{
				if(num[p].listed==0)
				{
					num[p].listed=1;
					count1++;
			//		printf("Hola, I got increased due to temp=%d and  p=%d\n",temp,p);
				}
				
			}
		}
	}
	//printf("Current p is %d while count1 is %d\n",p,count1);
}

int main()
{
	int n,i,j,k,g1,g2;
	node *num;
	si(n)
	num=(node *)malloc((n+1)*sizeof(node));
	FORi(i,1,n+1)
	{
		num[i].initialize(i);
	}
	FOR(i,n-1)
	{
		si(g1)
		si(g2)
		num[g1].adj.push_back(g2);
		num[g2].adj.push_back(g1);
	}
	count1=0;
	num[1].parent=0;
	dfs(num,1);
	pi(count1)
}