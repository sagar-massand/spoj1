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
	short int flag[20002],flag2[20002];
	int n,i,groups=0,temp;
	FOR(i,20002)
	{
		flag[i]=0;
	}
	si(n)
	FOR(i,n)
	{
		si(temp)
		if(flag[temp]==0)
		{
			//flag[temp]=5;
			flag[temp+1]++;
			flag[temp-1]++;
			groups++;
		}
		else if(flag[temp]==1)
		{
		//	flag[temp]=5;
			flag[temp+1]++;
			flag[temp-1]++;
		}
		else if(flag[temp]==2)
		{

			groups--;

		}
		pi(groups)
	}
	printf("Justice\n");
	return 0;
}