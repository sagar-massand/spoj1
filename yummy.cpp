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
	long long a[29];
//	a[0]=1;
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[4]=4;
	a[5]=6;
	a[6]=19;
	a[7]=43;
	a[8]=120;
	a[9]=307;
	a[10]=866;
	a[11]=2336;
	a[12]=6588;
	a[13]=18373;
	a[14]=52119;
	a[15]=147700;
	a[16]=422016;
	a[17]=1207477;
	a[18]=3471067;
	int t,i,j,k;
	si(t)
	FOR(i,t)
	{
		si(j)
		printf("Case #%d: %lld\n",i+1,a[j]);
	}
	return 0;
}