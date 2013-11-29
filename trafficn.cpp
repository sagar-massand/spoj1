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

//This class is used for storing the location of the adjacent node and the weight of the edge b/n those 2 nodes

class wit
{
public:
	int numb;
	int weight;
	void initialize(int a, int b)
	{
		numb=a;
		weight=b;
	}
};

//The node class stores everything from visited to distance frm base node(dist),numa is the node number, as also visited.

class node
{
public:
	std::vector<wit> forward;
	int numa;
	int position;
	int dist;
	int visited;
	void initialize()
	{
		
		dist=max;
		forward.clear();
	//	numa=a;
		visited=0;
	}
};
bool operator< (const node a,const node b)
{
//	if(a.dist!=b.dist)
		return (a.dist>b.dist);
//	else
//		return (a.city_num>b.city_num);
}

void initi(node *num,node *num2,int n,int m)
{
	int i,j,k;
	int first,last,length;
	wit r1,r2;
	FOR(i,m)
	{
		scanf("%d%d%d",&first,&last,&length);
		r1.initialize(last,length);
		r2.initialize(first,length);
		num[first].forward.push_back(r1);
		num2[last].forward.push_back(r2);
	}
}

/*void dfs(node *num,int count,priority_queue <node> MyQ)
{
/*	node temp=MyQ.top();
	int current=temp.numa;
	MyQ.pop();
	num[current].position=count;
	//num[current].visited=1;
	int i,j,k;
	while(!MyQ.empty)
		FOR(i,temp.forward.size())
		{
			if((temp.forward[i].weight+temp.dist)<(num[temp.forward[i].numb].dist))
			{
				num[temp.forward[i].numb].dist=(temp.forward[i].weight+temp.dist);
			}
			if(num[temp.forward[i].numb].visited==0)
			{
				MyQ.push(num[temp.forward[i].numb]);
				num[temp.forward[i].numb].visited=1;
			}
		}
		count++;
}
*/
/*void dfs(node *num,priority_queue <node> MyQ)
{
	node temp;
	int i,j,k;
	while(!MyQ.empty())
	{
		temp=MyQ.top();
		MyQ.pop();
		//j=temp.dist;
		//k=temp.numa;
		printf("Distance of %d is %d\n",k,j);
		FOR(i,temp.forward.size())
		{
			if((temp.forward[i].weight+temp.dist)<(num[temp.forward[i].numb].dist))
			{
				num[temp.forward[i].numb].dist=(temp.forward[i].weight+temp.dist);
			}
			if(num[temp.forward[i].numb].visited==0)
			{
				MyQ.push(num[temp.forward[i].numb]);
				num[temp.forward[i].numb].visited=1;
			}
		}
	}
}*/
int main()
{
	node num[12000];
	node num2[12000];
	int p,n,m,k,s,t,i,j,a,b,c,d,e,f,q;
	int count;
	int g1,g2,length,first,last,final_length;
	priority_queue <node> MyQ;
	si(f)
	FOR(q,f)
	{
		count=1;
		scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
		FORi(j,1,n+1)
		{
			num[j].initialize();
			num2[j].initialize();
		}

	
		node temp;
	//	initi(num,num2,n,m);
		wit r1,r2;
		FOR(i,m)
		{
			scanf("%d%d%d",&first,&last,&length);
			r1.initialize(last,length);
			r2.initialize(first,length);
			num[first].forward.push_back(r1);
			num2[last].forward.push_back(r2);
		}
	//	MyQ.clear();
		num[s].dist=0;
		num[s].visited=1;
		MyQ.push(num[s]);
		//dfs(num,MyQ);
	//	ps("")
		while(!MyQ.empty())
		{
			temp=MyQ.top();
			MyQ.pop();
			d=temp.dist;
			e=temp.numa;
	//		printf("Distance of %d is %d\n",e,d);
			final_length=temp.forward.size();
			FOR(i,final_length)
			{
				if((temp.forward[i].weight+temp.dist)<(num[temp.forward[i].numb].dist))
				{
					num[temp.forward[i].numb].dist=(temp.forward[i].weight+temp.dist);
				}
				if(num[temp.forward[i].numb].visited==0)
				{
					MyQ.push(num[temp.forward[i].numb]);
					num[temp.forward[i].numb].visited=1;
				}
			}
		}
		//dfs(num,count,MyQ);
	//	count=1;
	//	ps("Break b4 2nd dfs")
		num2[t].dist=0;
		num2[t].visited=1;
		MyQ.push(num2[t]);
	//	dfs(num2,MyQ);
		while(!MyQ.empty())

		{
			temp=MyQ.top();
			MyQ.pop();
		//	printf("Distance of %d is %d\n",e,d);
			FOR(i,temp.forward.size())
			{
				if((temp.forward[i].weight+temp.dist)<(num2[temp.forward[i].numb].dist))
				{
					num2[temp.forward[i].numb].dist=(temp.forward[i].weight+temp.dist);
				}
				if(num2[temp.forward[i].numb].visited==0)
				{
					MyQ.push(num2[temp.forward[i].numb]);
					num2[temp.forward[i].numb].visited=1;
				}
			}
		}
	//	ps("Hello")
/*		FORi(j,1,n+1)
			pi(num[j].dist)
		FORi(j,1,n+1)
			pi(num[j].dist)
*/		int min;
		min=num[t].dist;
		//pi(min)
		FOR(j,k)
		{
			int x,y;
			scanf("%d%d%d",&g1,&g2,&length);
			x=(num[g1].dist+length+num2[g2].dist);
			y=(num[g2].dist+length+num2[g1].dist);
			if(x<min)
				min=x;
			if(y<min)
				min=y;
		//	pi(min)
		}
		//ps("HHI")
		if(min>=max)
			ps("-1")
		else
			pi(min)
	}
	return 0;
}