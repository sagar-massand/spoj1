#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

/*First,check for presence of local minima or maxima except at the edges. O(logn)
Then, go separately for both jobs.
First, start frm left and check for minima
Second, start from left and then check for maxima. 
*/
int check_min(int *a,int n)
{
	
}
int main()
{
	int i,j,k,n,flag1,flag2,temp1,temp2;
	int a[1000000];
	while(si(n))
	{
		FOR(i,n)
		{
			si(a[i])
		}
		flag1=check_min(a,n);
		flag2=check_max(a,n);
		if((flag1==-1)&&(flag2==-1))
		{
			ps("-1")
		}
		else
		{
			flag1=find_min(a,n);
			flag2=find_max(a,n);
		}
		temp1=(a[flag1+1]+a[flag1-1]-(2*a[flag1]));

	}

	return 0;
}