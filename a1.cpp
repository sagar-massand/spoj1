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


#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);


#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	int i,j,k,n;
	int count[8]={0,0,0,0,0,0,0,0};
	si(n)
	FOR(i,n)
	{
		si(j)
		count[j]++;
	}
	if(count[5]||count[7])
	{
		ps("-1")
	}
	else
	{
		if(count[1]!=(count[2]+count[3]))
		{
			ps("-1")
		}
		else
		{
			if((count[2]+count[3])!=(count[4]+count[6]))
			{
				ps("-1")
			}
			else
			{
				if(count[3]<=count[6])
				{
					FOR(j,count[4])
					{
						printf("1 2 4\n");
						count[2]--;
					}
					FOR(j,count[2])
					{
						ps("1 2 6")
					}
					FOR(j,count[3])
					{
						ps("1 3 6")
					}

				}
				else
				{
					ps("-1")
				}
			}
		}
	}
}