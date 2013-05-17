//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>
#include<string.h>
//using namespace std;

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
	long long n,i,j,k,sum,flag=0,count;
	short int ans[1000000];
	long long a[1000000];

	scanf("%lld",&n);
	while(n!=0)
	{

		flag=0;
		count=0;
		FOR(i,n)
		{
			sl(a[i]);
			ans[i]=1;
		}	
		for(i=n-1;i>=0;i--)
		{
			flag=0;
			if(ans[i]==1)
			{
				if(a[i]<0)
				{
					ans[i]=0;
					sum=a[i]+a[(i+n-1)%n];
					for(j=i-1;((j+n)%n)!=i;j--)
					{
						if(sum>0)
						{
							flag=1;
							break;
						}
						else
						{
							ans[j]=0;
							if(sum>a[(j+n)%n])
							{
								sum=a[(j+n)%n];
							}
							sum+=a[(j+n-1)%n];
						}
					}
				}
			}
		}

		FOR(i,n)
		{
			if(ans[i]==1)
				count++;
		}
		pl(count)

	}
	return 0;
}