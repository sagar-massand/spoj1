#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
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
	int n,m,i,j,k,a,b,flag,prnt;
	int t;
	int *count;
	si(n)
	si(m)
	count=(int *)malloc((n+1)*sizeof(int));
	FOR(i,n+1)
	{
		count[i]=0;
	}
	FOR(i,m)
	{
		si(a)
		si(b)
		count[a]++;
		count[b]++;
	}
	if(n>=1)
	{
		if(n==(m+1))
		{
			prnt=0;
			flag=0;
			FORi(i,1,n+1)
			{
				if(count[i]==0)
				{
					ps("NO")
					prnt=1;
					break;
				}
				else if(count[i]>2)
				{
					prnt=1;
					ps("NO")
					break;
				}
			}
			if(prnt==0)
			{
				ps("YES")
			}
		}
		else
		{
			ps("NO")
		}
	}
	else
	{
		ps("YES")
	}
	return 0;
}