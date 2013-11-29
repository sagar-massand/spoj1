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
	std::vector<int> ancestor;
	//int visited;
	//int start;
	//int end;
	//int next;
	//int prev;
	int parent;
	int level;
	void initialize(int n)
	{
	//	visited=0;
		adj.clear();
		ancestor.clear();
		level=(n+1);
	}
};

int take_input(node *num,int n)
{
	int i,j,k,temp,m;
	int *visited;
	visited=(int *)malloc((n+1)*sizeof(int));
	j=0,k=1;
	while(k<=n)
	{	
		FORi(i,1,n+1)
		{
			num[i].ancestor.push_back(0);
		}
		j++;
		k*=2;
	}
	FORi(i,1,n+1)
	{
		si(m)
		FOR(j,m)
		{
			si(temp)
			num[i].adj.push_back(temp);
			//visited[temp]=1;
			num[temp].ancestor[0]=i;
		}
	}
	FORi(i,1,n+1)
	{
		if(num[i].ancestor[0]==0)
			return i;
	}
}

void assignment(node *num, int n,int root)
{
	int i,j,k;
	j=1,k=2;
	while(k<=n)
	{
		FORi(i,1,n+1)
		{
			if(num[i].ancestor[j-1]!=0)
			{
				num[i].ancestor[j]=num[num[i].ancestor[j-1]].ancestor[j-1];
			}
		}
		j++;
		k*=2;
	}
}
void bfs(node *num,int n,int root)
{
	int temp,i,j,k;
	queue<int> MyQ;
	MyQ.push(root);
	while(!MyQ.empty())
	{
		temp=MyQ.front();
		MyQ.pop();
		FOR(i,num[temp].adj.size())
		{
			j=num[temp].adj[i];
			num[j].level=(num[temp].level+1);
			MyQ.push(j);
		}
	}
}
int find_samelevel(node *num,int n,int anc,int dec)
{
	int temp,i,j=0,k,flag=0,temp1;
	temp1=dec;
	while(temp1!=0)
	{
		flag=0;
		j=0;
		temp=num[temp1].ancestor[0];
		while(temp!=0)
		{
			if(num[temp].level==num[anc].level)
			{
				return temp;
			}
			else if(num[temp].level<num[anc].level)
			{
				flag=1;
				break;
			}
			j++;
			temp=num[temp1].ancestor[j];
		}
		j-=1;
		temp1=num[temp1].ancestor[j];
	}
}
int anc_samelevel(node *num,int n,int p1,int p2)
{
	int i,j=0,k,a,b,c,temp,temp1,r1,r2;
	/*while(num[p1].ancestor[j]!=num[p2].ancestor[j])
	{
		j++;
	}*/
	temp=p1;
	temp1=p2;	
	r1=p1;
	r2=p2;
	while(r1!=r2)
	{
		j=0;
		temp=num[r1].ancestor[0];
		temp1=num[r2].ancestor[0];
		while(temp!=temp1)
		{
			j++;
			temp=num[r1].ancestor[j];
			temp1=num[r2].ancestor[j];
		}
		j--;
		r1=num[r1].ancestor[j];
		r2=num[r2].ancestor[j];
		if(j<0)
			return temp;

	}
	return temp;

}
void query(node *num,int n,int root)
{
	int q,g1,g2,temp,i,j,k,a,b,c,ans;
	si(q)
	FOR(a,q)
	{
		si(g1)
		si(g2)
		if(num[g1].level==num[g2].level)
		{
			ans=anc_samelevel(num,n,g1,g2);
		}
		else
		{
			if(num[g1].level>num[g2].level)
			{
				temp=find_samelevel(num,n,g2,g1);
			//	printf("Temp is %d\n",temp);
				ans=anc_samelevel(num,n,temp,g2);
			}
			else
			{
				temp=find_samelevel(num,n,g1,g2);
			//	printf("Temp is %d\n",temp);
				ans=anc_samelevel(num,n,temp,g1);
			}
		}
		pi(ans)
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
			num[j].initialize(n);
		}
		root=take_input(num,n);
		//find_root(num,n);
		//pi(root)
		//count1=0;
		num[root].level=1;
		bfs(num,n,root);
/*		FORi(j,1,n+1)
		{
			pi(num[j].start)
			pi(num[j].end)
		}
*/		
		assignment(num,n,root);
		query(num,n,root);
	}

}