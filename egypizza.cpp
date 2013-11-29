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

#define pf(n)		printf("%lf\n",n);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define FORi(i,a,b)	for(i=a;i<b;i++)

int main()
{
	int count_q=0,count_h=0,count_3q=0,count=1;
	int n,i;
	char ch[10];
	si(n)
	FOR(i,n)
	{
		ss(ch)
		if(ch[2]=='2')
		{
			count_h++;
		}
		else
		{
			if(ch[0]=='1')
				count_q++;
			else
				count_3q++;
		}
	}
	if(count_q>=count_3q)
	{
		count_q-=count_3q;
		count+=count_3q;
		count+=(count_h/2);
		count_h-=(2*(count_h/2));
		if(count_h==1)
		{
			count_q-=2;
			count++;
		}
		if(count_q>0)
		{
			count+=(count_q/4);
			count_q-=(4*(count_q/4));
			if(count_q>0)
				count++;
		}
	}
	else
	{
		count+=count_3q;
		count+=(count_h/2);
		if(count_h%2==1)
			count++;
	}
	pi(count)
}