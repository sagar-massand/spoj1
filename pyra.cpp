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

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define FORi(i,a,n)	for(i=a;i<n;i++)

std::vector<long long> num[10000];
int visited[10000];
long long final;
long long find_size(long long a)
{
	//ps("find_size")
	long long ans=0,j,k,i;
	ans+=num[a].size();
	k=num[a].size();
	visited[a]=1;
	//printf("num[%lld].size is %lld\n",a,k);
	FOR(j,num[a].size())
	{
		if(visited[num[a][j]]==0)
			ans+=find_size(num[a][j]);
	}
	final+=ans;
	return ans;
}

int main()
{
	long long a,b,c,ans,n,t,i,j,k;
	sl(t)
	FOR(i,t)
	{
		sl(n)
		//ps("Here")
		FOR(j,n)
		{
			num[j].clear();
			visited[j]=0;
		}
		FOR(j,n-1)
		{
			sl(a)
			sl(b)
			num[a].push_back(b);
			num[b].push_back(a);
			visited[j]=0;
		}
		//ps("Say")
		visited[n-1]=0;
		ans=0;
		final=0;
		ans+=(num[0].size()+1);
		//pl(ans)
		visited[0]=1;
		//ps("Die")
		b=num[0].size();
		//pl(b)
		FOR(j,num[0].size())
		{
			ans+=find_size(num[0][j]);
			//pl(ans)
		}
	//	ps("live")
		//pl(ans)
		final+=ans;
		pl(final)
	}
}