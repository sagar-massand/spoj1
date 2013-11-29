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

#define FORi(i,a,n)	for(i=a;i<n;i++)

void dfs(int num,int num1,int *visited,std::vector<int> *adj)
{
	//ps("Hello")
	visited[num]=num1;
	int i,j,k;
	FOR(i,adj[num].size())
	{
	//	ps("HI")
	//	pi(num)
		if(visited[adj[num][i]]!=num1)
		{
			dfs(adj[num][i],num1,visited,adj);
		}
	}
}

int main()
{
	
	//std::vector<int> p_adj[1001];
	int t,i,j,k,n,num,temp,flag;
	si(t)
	FOR(i,t)
	{
		std::vector<int> adj[1001];
		set <int> MySet;
		int *visited;
		int ans=0;
		si(n)
		int count=0;
		visited=(int *)malloc((n+1)*sizeof(int));
		FORi(j,1,n+1)
		{
			visited[j]=0;
			si(num)
			FOR(k,num)
			{
				si(temp)
				//adj.push_back(temp);
				adj[temp].push_back(j);
			}
		}
	//	ps("I  am here")
		FORi(j,1,n+1)
		{
			/*FOR(k,adj[j].size())	
			{

			}*/
			flag=0;
			dfs(j,j,visited,adj);
			k=1;
			while((k<=n))
			{
				if(visited[k]!=j)
				{
					flag=1;
					break;
				}
				k++;
			}
			if(flag==0)
				count++;

		}	
		pi(count)
	}
}