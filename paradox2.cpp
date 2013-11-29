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

#define pb			push_back

#define inf 1000000007

#define max 10000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	int n,i,j,k;
	char ch[10];
	si(n)
	while(n!=0)
	{
		int ans=0;
		int num1[120],num2[120],flag[120],label[120];
		FORi(i,1,n+1)
		{
			si(num1[i])
			ss(ch)
			if(ch[0]=='f')
				num2[i]=0;
			else
				num2[i]=1;
			flag[i]=2;
			label[i]=0;
		}
		FORi(i,1,n+1)
		{
			if(label[i]==0)
			{
				label[i]=i;
				j=i;
				k=num1[j];
				flag[j]=1;
				while(label[k]==0)
				{
					flag[k]=!(num2[j]^flag[j]);
					label[k]=i;
					j=k;
					k=num1[j];
				}
				if(label[k]==i)
				{
					if(flag[k]!=(!(num2[j]^flag[j])))
					{
						ans=1;
						break;
					}
				}
			}
		}
		if(ans==1)
		{
			ps("PARADOX")
		}
		else
			ps("NOT PARADOX")
		si(n)
	}
	return 0;
}