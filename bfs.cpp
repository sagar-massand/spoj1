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

#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

class node
{
	std::vector<int> adj;
	int visited;
	void ini()
	{
		adj.clear();
		visited=0;
	}
};


int main()
{
	int n,m,i,j,k,temp1,temp2,start;
	node *final;
	queue<int> num;
	si(n)
	si(m)
	final=(node *)malloc((n+1)*sizeof(node));
	FORi(i,1,n+1)
	{
		final[i].ini();
	}
	FOR(i,m)
	{
		si(temp1)
		si(temp2)
		final[temp1].adj.push_back(temp2);
		final[temp2].adj.push_back(temp1);	
	}
	si(start)
	num.push(start);
	node[start].visited=1;
	while(!num.isempty())
	{
		temp1=queue.top();
		queue.pop();
		FOR(i,node[temp1].adj.size())
		{
			queue.push(node[temp1].adj[i]);
		}
	}
}