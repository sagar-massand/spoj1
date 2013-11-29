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

class node
{
	std::vector<wit> adj;
	int size1;
	int count_sub;
	int visited;
	int first;
	int second;
	void initialize()
	{
		size1=0;
		count_sub=0;
		visited=0;
		first=0;
		second=0;
	}

};
void dfs(node *fin,int x,int k)
{
	int i,j,temp,a;
	FOR(i,fin[x].adj.size())
	{
		temp=fin[x].adj[i];
		if(fin[temp].visited==0)
		{
			fin[temp].visited=1;
			dfs(fin,temp,k);
			fin[x].size1+=(fin[temp].size1+1);
			fin[x].count_sub+=(fin[temp].count_sub);
			if((fin[temp].first+1)>fin[x].second)
			{
				fin[x].second=(fin[temp].first+1);
				if(fin[x].second>fin[x].first)
				{
					a=fin[x].first;
					fin[x].first=fin[x].second;
					fin[x].second=a;
				}
			}
			if((fin[temp].second+1)>fin[x].first)
		}
	}

}
int main()
{
	node *fin;
	int t,n,k,a,b,c,temp1,temp2;
	si(t)
	FOR(a,t)
	{
		si(n)
		si(k)
		fin=(node *)malloc((n+1)*sizeof(node));
		FOR(b,n+1)
		{
			fin[b].initialize();
		}
		FOR(b,n-1)
		{
			si(temp1)
			si(temp2)
			fin[temp1].push_back(temp2);
			fin[temp2].push_back(temp1);
		}
		dfs(fin,1,k);
	}
}