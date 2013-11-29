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
	long long weight_br;
	long long sqr;
	void ini()
	{
		parent=0;
		visited=0;
		weight=0;
		weight_br=0;
		adj.clear();
		sqr=0;
	} 
};
void dfs(node *final,long long p)
{
	long long temp,i,j,k,sum=0,num=0,fin=0,temp2,temp3;
	final[p].visited=1;
//	printf("I am in %lld\n",p);
//	cout<<final[p].adj.size()<<endl;
	FOR(i,final[p].adj.size())
	{
		if(final[p].adj[i].el!=(final[p].parent))
		{
//			ps("Hurry")
			temp=final[p].adj[i].el;
//			printf("Temp is %lld\n",temp);
			final[temp].parent=p;
			dfs(final,temp);
			temp2=(final[p].adj[i].wt*(1+final[temp].weight_br));
			temp2%=mod;
			final[p].weight_br+=temp2;
			final[p].weight_br%=mod;
			//final[p].sqr=(temp2*temp2);
			//fin+=(temp2*temp2);
			fin%=mod;
			final[p].weight+=final[temp].weight;
			final[p].weight%=mod;
			final[p].weight+=temp2;
			final[p].weight%=mod;
		}
	}
	temp2=0;
//	temp=final[p].adj[0].el;
//	if(temp==final[p])
//	temp2=final[p].adj[0].wt*(1+final[temp].weight_br);
	FOR(i,final[p].adj.size())
	{

		temp=final[p].adj[i].el;
		if(temp!=final[p].parent)
		{
			temp3=(final[p].adj[i].wt*(1+final[temp].weight_br));
			num+=(temp2*temp3);
			num%=mod;
			temp2+=temp3;
			temp2%=mod;
		}
		
	}
//	printf("Num is %lld\n",num);
/*	if(num<0)
		num+=mod;
	else
		num%=mod;
*/	final[p].weight+=num;
	final[p].weight%=mod;
//	printf("P is %lld while weight is %lld and weight_br is %lld\n",p,final[p].weight,final[p].weight_br);
}
/*long long dfs(node *final,long long p)
{
	long long temp,i,j,k,sum=0,ans,num=0,fin=0;
	final[p].visited=1;
	printf("I am in %lld\n",p);
	cout<<final[p].adj.size()<<endl;
	FOR(i,final[p].adj.size())
	{
		if(final[p].adj[i].el!=(final[p].parent))
		{
			ps("Hurry")
			temp=final[p].adj[i].el;
			printf("Temp is %lld\n",temp);
			final[temp].parent=p;
			final[temp].weight=dfs(final,temp);
			fin+=final[temp].weight;
			fin%=mod;
			final[temp].weight++;
			final[temp].weight*=(final[p].adj[i].wt);
			final[temp].weight%=mod;
			final[temp].sqr=(final[temp].weight*final[temp].weight);
			final[temp].sqr%=mod;
			sum+=final[temp].weight;
			sum%=mod;
			num+=final[temp].sqr;
			num%=mod;
		}
		
	}
	pl(fin)
	pl(sum)
	pl(num)
	ans=((sum*sum-num)/2);
	if(ans>=0)
	{
		ans%=mod;
	}
	else
	{
		ans+=mod;
	}
	ans+=sum;
	ans+=fin;
	return ans;

}*/
int main()
{
	wit num;
	long long n,i,j,k,a,b,w,ans;
	sl(n)
	node *final;
	node ans1;
	final=(node *)malloc((n+1)*sizeof(node));
	FOR(i,n)
	{
//		ps("Bye")
		final[i+1].ini();
	}
	FOR(i,n-1)
	{
	//	ps("Hi")
		sl(a)
		sl(b)
		sl(w)
		num.ini(b,w);
		final[a].adj.push_back(num);
		num.ini(a,w);
		final[b].adj.push_back(num);	
	}
	//ps("Gello")
	dfs(final,1);
	pl(final[1].weight)
}
/*    11
    2 1 1000
    8 6 1000
    1 3 1000
    3 4 1000
    3 5 1000
    3 6 1000
    6 7 1000
    6 9 999
    6 10 998
    6 11 997
    
   */