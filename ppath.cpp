#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
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



class ppath
{
public:
	//ppath(arguments);
	//~ppath();
	int n;
	std::vector<int> v;

	/* data */
};

std::vector<int> create_adjacency(int i, int n,int *prim_search)
{
//public:
//	v(arguments);
//	~v();
	//p.v.push_back(i);
	//p.v.push_back(n);
	/* data */

	std::vector<int> v;
	//ppath score;
	//v.push_back(i);
	//v.push_back(n);
	int j,k,a,b,c;
	int *x;
	j=1000;
//	ps("I got here")
	while(j>0)
	{
		k=10*j;
		a=(n/k)*k;
		b=n-j;
		while(b>=a)
		{
//			ps("Even here, in d downward loop")
			if((prim_search[b]==1)&&(b%2==1)&&(b>=1000))
				v.push_back(b);
			b-=j;
		}
		a+=k;
		b=n+j;
		while(b<a)
		{
//			ps("Even here, in d upward loop")
			if((prim_search[b]==1)&&(b%2==1)&&(b>=1000))
				v.push_back(b);
			b+=j;
		}	
		j/=10;

	}
	return v;

}

int find_index(int n,int *prime,int total)
{
	int ans,mid;
	int start=0,end=total-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(n>prime[mid])
		{
			start=mid+1;
		}
		else if(n<prime[mid])
		{
			end=mid-1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int prime[2000],prim_search[10001];
	int i,j,k,a,b,c,total,t,y,z,x;
	//int *neighbour
	FOR(i,10001)
	{
		prim_search[i]=1;
	}
	prim_search[0]=0;
	prim_search[1]=0;
	prime[0]=2;
	prime[1]=3;
	k=2;
	for(i=3;i<100;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			for(j=i*i;j<10000;j+=(2*i))
			{
				prim_search[j]=0;
			}
			k++;
		}	
	}
	for(;i<10000;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			k++;
		}
	}
	total=k;
	std::vector<int> fin[2000];
	int visited[2000],distance[2000];
	//std::vector<ppath> gin[2000];
	int start,end,start_index,end_index;
	std::vector<int> v;
	//std::vector<ppath> gin;
	//ppath temp1;
	
	FOR(i,total)
	{
		//create_adjacency(i,prime[i],v[i]);
		//j=v[i][1];
		//pi(j)
		fin[i]=create_adjacency(i,prime[i],prim_search);
//		j=fin[i][0];
		//pi(prime[i])
		//std::cout<<fin[i].size()<<endl;
	/*	for(x=fin[i].begin;x<=fin[i].end;x++)
		{
			pi(*x)
		}
	*/
	/*	FOR(j,fin[i].size())
			pi(fin[i][j]);
		ps("\n")
		//temp1=create_adjacency(i,prime[i]);
		//gin.push_back(temp1);
		//j=gin[i].v[0];
		//pi(j)
	*/
	}
	si(t)
	FOR(i,t)
	{
		queue <int> bfs;
		FOR(j,total)
		{
			visited[j]=0;
			//distance[j]=2000;
		}	
		int temp,flag=0,temp2;
		si(start)
		si(end)
		start_index=find_index(start,prime,total);
		end_index=find_index(end,prime,total);
		visited[start_index]=1;
		distance[start_index]=0;
		//ps("Before queue")
		bfs.push(start_index);
		//ps("After queue")
		if(start_index==end_index)
		{
			ps("0")
			continue;
		}
		else
		{
			//ps("After queu2")
			while(!bfs.empty())
			{
				//ps("I am here")
				//pi(bfs.size())
				temp=bfs.front();
				//bfs.pop();
				//ps("\n")
				//printf("Prime is %d\n\n",prime[temp]);
				for(j=0;j<fin[temp].size();j++)
				{
					//ps("I will stay here")

					if(fin[temp][j]==end)
					{
						flag=1;
						pi(distance[temp]+1)
						break;
					}
					temp2=find_index(fin[temp][j],prime,total);
					//printf("Index for fin[%d][%d] which is %d is %d\n",temp,j,fin[temp][j],temp2);
					if(visited[temp2]==0)
					{
					//	printf("Visited prime is %d\n",prime[temp2]);
						visited[temp2]=1;
						distance[temp2]=(distance[temp]+1);
						bfs.push(temp2);
					}
				}
				if(flag==1)
					break;
				bfs.pop();
			}
			if(flag==1)
				continue;
			else
				ps("Impossible")
		}
	}

	return 0;

}