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

long long sum;

class wit
{
public:
	long long el;
	long long wt;
	void ini(long long a,long long b)
	{
		el=a;
		wt=b;
	}
};

class node
{
public:
	std::vector<wit> adj;
	long long parent;
	long long visited;
	long long weight;
	//long long weight_br;
	//long long sqr;
	void ini()
	{
		parent=0;
		visited=0;
		weight=0;
	//	weight_br=0;
	//	adj.clear();
	//	sqr=0;
	} 
	void in()
	{
		parent=0;
		visited=0;
		weight=0;
		adj.clear();
	}
};

int main()
{
	wit num;
	long long n,i,j,k,temp;
	node *final;
	//long long *num;
	sum=0;
	final=(node *)malloc((n+1)*sizeof(node));
	FORi(i,1,n+1)
	{
		final[i].in();
	}
	FOR(i,n-1)
	{
		sl(j)
		sl(k)
		sl(temp)
		num.ini(k,temp);
		final[j].adj.push_back(num);
		num.ini(j,temp);
		final[k].adj.push_back(num);
		
	}
	FORi(i,1,n+1)
	{
		bfs(final,i);
	}
}