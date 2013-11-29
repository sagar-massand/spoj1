#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
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

int find_max(int temp)
{
	int counter=1;
	int *visited=(int *)malloc(n*sizeof(int));
	FOR(i,n)
		visited[i]=0;
	visited[temp]=1;
	

}

int main()
{
	int n,c,i,j,k;
	
	si(n)
	si(c)
	while(n!=0)
	{
		
		int temp,temp2,temp3,max=0;
		int *count=(int *)malloc(n*sizeof(int));
		int *city_confed=(int *)malloc(n*sizeof(int));
		int *city_confed1=(int *)malloc(n*sizeof(int));
		FOR(i,n)
			city_confed1=k+3;
		std::vector<int> city[1004];
		std::vector<int> confed[102];
		FORi(i,1,k+1)
		{
			si(temp)
			if(count[temp]==0)
			{
				//MyQ.push_back(temp);
				confed[i].push_back(temp);
				city_confed[temp]=i;
				//city_confed[temp]=i;
				count[temp]++;
			}
			else
			{
				//MyQ.push_back(temp);
				confed[i].push_back(temp);
				city_confed1[temp]=i;
				count[temp]++;
			}
		}
		max=0;
		FOR(temp,n)
		{
			max=find_max(temp,count);

			/*FOR(k,2)
			{
				if(count[temp]==k)
					break;
				int counter=0;
				temp3=(temp+(k*n));
				queue <int>MyQ;
			//	stack <int> MyStack;
				int *visited=(int *)malloc(2*n*sizeof(int));
				FOR(j,2*n)
					visited[j]=0;
				visited[temp3]=1;
				MyQ.push_back(temp3);
				while(!MyQ.isempty())
				{
					temp2=MyQ.front();
					MyQ.pop_front();
					FOR(j,confed[city_confed[temp2]].size())
					{
						if(count[confed[city_confed[temp2]]][j]==1)
						{
							visited[confed[city_confed[temp2]]]=1;
							counter++;
						}
						else
						{
							visited[confed[city_confed[temp2]]]=1;

						}
					}


				}
			}*/


		}