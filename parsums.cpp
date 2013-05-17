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

//#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	long long n,i,j,k,sum,flag=0,count;
	short int *ans;
	long long *a;

	sl(n);
	while(n!=0)
	{
		a=(long long *)malloc(n*sizeof(long long));
		ans=(short int*)malloc(n*sizeof(short int));

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
					//ps("Yes, i did get here")
					//pl(i)
					ans[i]=0;
					sum=a[i]+a[(i+n-1)%n];
					for(j=i-1;((j+n)%n)!=i;j--)
					{
						//printf("Sum at j=%lld is %lld\n",j,sum);
						if(sum>=0)
						{
						//	pl(j)
							flag=1;
							break;
						}
						else
						{
							ans[(j+n)%n]=0;
							sum+=a[(j+n-1)%n];
						}

					}
				}
			}
		}

		FOR(i,n)
		{
			if(ans[i]==1)
			{
				//pl(i)
				count++;
			}
		}
		pl(count);
		
		free(ans);
		free(a);
		sl(n);

	}
	return 0;
}