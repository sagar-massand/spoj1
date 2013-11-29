#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
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
	int num[101],flag2[101],flag[101],visited[101];
	int n,i,j,k;
	char ch[10];
	si(n)
	while(n!=0)
	{
		FORi(i,1,n+1)
		{
			visited[i]=0;
			flag[i]=0;
			si(num[i])
			ss(ch)
			if(ch[0]=='f')
				flag2[i]=2;
			else
				flag2[i]=1;
		}

		FORi(i,1,n+1)
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				flag[i]=1;
				j=i;
				while(visited[num[j]]==0)
				{
					flag[num[j]]=flag2[j];
					visited[num[j]]=1;
					j=num[j];
				}
				if(flag2[j]!=flag[num[j]])
				{
					visited[i]=1;
					flag[i]=2;
					j=i;
					while(visited[num[j]]==0)
					{
						flag[num[j]]=flag2[j];
						visited[num[j]]=1;
						j=num[j];
					}

				}
			}
		}
	}
}