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

int main()
{
	int n,i,j,k,temp,t=1;
	int sum1,ans1,ans2;
	
	si(n)
	while(n!=0)
	{
		int **num;
		int *sum;
		num=(int **)malloc(n*sizeof(int *));
		sum=(int *)malloc(n*sizeof(int));
		FOR(i,n)
		{
			num[i]=(int *)malloc(n*sizeof(int));
			sum[i]=0;
		}
		ans1=0,ans2=0;
		FOR(i,n)
		{
			//sum[i]=0;
			FOR(j,n)
			{
				si(num[i][j])
				ans1+=num[i][j];
				sum[j]+=num[i][j];
				sum[i]-=num[i][j];
				//si(temp)
				//v[i].push_back(temp)

			}
		}
		
		FOR(i,n)
		{
			if(sum[i]>0)
			{
				ans2+=sum[i];
			}
			//ans1+=sum[i];
		}
		printf("%d. %d %d\n",t,ans1,ans2);
		t++;
		si(n)
		
	}
	return 0;
}