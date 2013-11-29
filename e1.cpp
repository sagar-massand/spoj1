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


#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);


#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

class node
{
	std::vector<int> v;
	//int flag;
	int dist;
	int parent;
	void ini()
	{
		flag=0;
		dist=0;
		v.clear();
		parent=0;
	}
};

int main()
{
	node *final;
	int n,m,i,j,k;
	si(n)
	si(m)
	final=(node *)malloc((n+1)*sizeof(node));
	FORi(i,1,n+1)
	{
		final[i].ini();
	}
	FOR(i,n)
	{
		si(j)
		si(k)
		final[j].v.push_back(k);
		final[k].v.push_back(j);		
	}

}