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
public:
	std::vector<int> adj;
	int visited;
	int start;
	int end;
	//int next;
	//int prev;
	int parent;
	void initialize()
	{
		visited=0;
		adj.clear();
	}
};

/*void initialize(vector<int> *v,int n)
{
	int i,j,k;
	FORi(i,1,n+1)
	{
		v[i].clear();
	}
}
*/
int count1;
int take_input(node *num,int n)
{
	int i,j,k,temp,m;
	int *visited;
	visited=(int *)malloc((n+1)*sizeof(int));
	FORi(i,1,n+1)
	{
		visited[i]=0;
	}
	FORi(i,1,n+1)
	{
		si(m)
		FOR(j,m)
		{
			si(temp)
			num[i].adj.push_back(temp);
			visited[temp]=1;
			num[temp].parent=i;
		}
	}
	FORi(i,1,n+1)
	{
		if(visited[i]==0)
			return i;
	}
}
void dfs(node *num,int n,int cur)
{
	int i,j,k,temp;
	count1++;
//	pi(count1)
	num[cur].start=count1;
	//count1++;
	temp=num[cur].adj.size();
	FOR(i,temp)
	{
		dfs(num,n,num[cur].adj[i]);
	}
	count1++;
//	pi(count1)
	num[cur].end=count1;
}
int ancestor(int anc,int dec,node *num)
{
	if((num[anc].start<=num[dec].start)&&(num[anc].end>=num[dec].end))
		return anc;
	return 0;
}
void query(node *num,int n,int root)
{
	int q,g1,g2,temp;
	int cur1,cur2,flag;
	int i,j,k;
	si(q)
	FOR(i,q)
	{
		flag=0;
		si(g1)
		si(g2)
		if(temp=ancestor(g1,g2,num))
		{
			pi(temp)
		//	ps("G")
		}
		else if(temp=ancestor(g2,g1,num))
		{
			pi(temp)
		//	ps("Hello")
		}
		else
		{
			cur1=num[g1].parent;
			cur2=num[g2].parent;
			while((cur1!=root)&&(cur2!=root))
			{
				if(temp=ancestor(cur1,g2,num))
				{
					pi(temp)
					flag=1;
					break;
				}
				else if(temp=ancestor(cur2,g1,num))
				{
					pi(temp)
					flag=1;
					break;
				}
			}
			if(flag==0)
				pi(root)
		}
	}

}
int main()
{
	//std::vector<int> adj[200];
	node num[1010];
	int root,i,j,k,n,m,t;
	si(t)
	FOR(i,t)
	{
		printf("Case %d:\n",(i+1));
		si(n)
		FORi(j,1,n+1)
		{
			num[j].initialize();
		}
		root=take_input(num,n);
		//find_root(num,n);
		//pi(root)
		count1=0;
		dfs(num,n,root);
/*		FORi(j,1,n+1)
		{
			pi(num[j].start)
			pi(num[j].end)
		}
*/		query(num,n,root);
	}

}