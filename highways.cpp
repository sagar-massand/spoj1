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

#define inf 1000000000
class travel
{
public:
	long long city_num;
	long long dist;
	void initialize(long long city,long long distance)
	{
		city_num=city;
		dist=distance;
	}

};

bool operator< (const travel a,const travel b)
{
	if(a.dist!=b.dist)
		return (a.dist>b.dist);
	else
		return (a.city_num>b.city_num);
}

void bfs(long long n,long long start,long long end,std::vector<travel> *city)
{
	travel temp,temp2;

	long long i,j,k,min,current,flag=0;
	travel *num;
	int *visited;
	num=(travel *)malloc((n+1)*sizeof(travel));
	visited=(int *)malloc((n+1)*sizeof(int));
	FOR(j,n+1)
	{
		num[j].initialize(j,inf);
		visited[j]=0;
	}
/*	FOR(j,n)
		pl(num[j].dist)
*/	num[start].dist=0;
	//set<long long> MySet;
	//MySet.push_back(start);
	priority_queue <travel> MyQ;
	//temp.initialize(start,0);
	MyQ.push(num[start]);
	while(!MyQ.empty())
	{
		temp2=MyQ.top();
		//printf("Node %lld is at distance %lld\n",temp2.city_num,temp2.dist);
		if(temp2.city_num==end)
		{
			flag=1;
			break;
		}
		visited[temp2.city_num]=1;
		MyQ.pop();
		FOR(j,city[temp2.city_num].size())
		{
		//	printf("Node %lld\n",temp2.city_num);
			temp=city[temp2.city_num][j];
			if(visited[temp.city_num]==1)
				continue;
			else
			{
				current=num[temp2.city_num].dist+temp.dist;
				if(current<num[temp.city_num].dist)
				{
					num[temp.city_num].dist=current;
				}
			}
			MyQ.push(num[temp.city_num]);
		//	printf("%lld is visited, at distance %lld\n",temp.city_num,num[temp.city_num].dist);
		}

		
	}
	if(num[end].dist<inf)
		pl(num[end].dist)
	else
		ps("NONE")	

}

int main()
{
	std::vector<travel> city[200000];
	long long t,n,i,j,k,start,end,m,a,b,distance;
	travel temp1,temp2;
	sl(t)
	FOR(i,t)
	{
		//ps("Here")
	//	long long *dist;
	//	dist=(long long *)malloc(n*sizeof(long long));
		

		sl(n)
		sl(m)
		sl(start)
		sl(end)
	/*	FOR(j,n)
			dist[i]=1e12;
	*/	FOR(j,m)
		{
			//ps("Helllo")
			scanf("%lld%lld%lld",&a,&b,&distance);
			temp1.initialize(b,distance);
			city[a].push_back(temp1);
			temp1.initialize(a,distance);
			city[b].push_back(temp1);
		}
		//dist[start]=0;
		bfs(n,start,end,city);
		//free(dist);
	}
}