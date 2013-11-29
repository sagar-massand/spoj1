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

int main()
{
	int n,c,i,j,k;
	
	si(n)
	si(c)
	while(n!=0)
	{
		
		int temp,temp2;
		int *count=(int *)malloc(n*sizeof(int));
		int *city_confed=(int *)malloc(2*n*sizeof(int));
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
				city_confed[temp+n]=i;
				count[temp]++;
			}
			else
			{
				//MyQ.push_back(temp);
				confed[i].push_back(temp+n);
				city_confed[temp+n]=i;
			}
		}
		FOR(temp,n)
		{
			FOR(k,2)
			{
				int temp3;
				int counter=0;
				queue <int>MyQ;
			//	stack <int> MyStack;
				int *visited=(int *)malloc(2*n*sizeof(int));
				FOR(j,2*n)
					visited[j]=0;
				temp3=temp;
				visited[temp3]=1;
				counter++;
				MyQ.push_back(temp3);
				while(!MyQ.isempty())
				{
					visited[temp2]=1;

					MyQ.pop_front(temp2);
					//MyStack.push_back(temp2);
					if(count[temp2]!=1)
						temp2+=n;
					for(j=0;j<confed[city_confed[temp2]].size();j++)
					{
						i=city_confed[temp2];
						if(confed[i][j]!=temp2)
						{
							if(count[confed[i][j]]==1)
							{
								MyQ.pop_front(confed[i][j]);
							}
							else
							{
								
							}
						}
					}
				}
			}
		}
	}
}