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
#include<time.h>
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

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int find_power(int n)
{
	int i=1,j,k;
	n--;
	while(n>0)
	{
		i*=2;
		n/=2;
	}
	return i;
}

int main()
{
	int n,i,j,k,q,m,check;
	int *num;
	char ch;
	int flag;
//	si(t)
	FOR(j,10)
	{
		si(n)
		int power=find_power(n);
		num=(int *)malloc((2*power)*sizeof(int));
		FOR(i,power-1)
		{
			num[i]=0;
		}
		FORi(i,power-1,power+n-1)
		{
			sc(ch)
			if(ch=='(')
			{
				num[i]=1;
			}
			else
			{
				num[i]=-1;
			}
		}
		FORi(i,power+n-1,2*power-1)
		{
			num[i]=0;
		}
		for(i=power+n-2;i>0;i--)
		{
			num[(i-1)/2]+=num[i];
		}
		si(m)
		printf("Test %d:\n",j+1);
		FOR(i,m)
		{
			si(q)
			if(q==0)
			{
				k=power-1;
				flag=0;
				while(k>0)
				{
					if(num[k]<0)
					{
						flag=1;
						break;
					}
					k=(k-1)/2;
				}
				if(flag==0)
				{
					if(num[0]==0)
						ps("YES")
					else
						ps("NO")
				}
				else
					ps("NO")
			}
			else
			{
				if(num[q+power-2]==1)
					check=-2;
				else
					check=2;
				for(k=q+power-2;k>0;)
				{
					num[k]+=check;
					k=(k-1)/2;
				}
				num[k]+=check;
			}
		}

	}
	return 0;
}
