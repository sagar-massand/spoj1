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

int main()
{
	char ch;
	char enc[1000],dec[1000],key[9]={10, 2, 6, 2, 3, 5, 2, 2, 1};
	int *freq[26];
	int i=0,num=8,final;
	while(scanf(" %c",&ch))
	{
		if((ch=='.')||(ch==','))
			continue;
		else
		{
			enc[i]=ch;
			i++;
		}
	}

	final=i;
	FOR(i,final)
	{
		dec[i]=(enc[i]+(key[i%9]));
	}
	FOR(i,final)
	{
		printf("%c",dec[i]);
	}
/*	FOR(i,26)
	{
		freq[i]=(int *)malloc(num*sizeof(int));
	}
	for(i=0;i<final;i++)
	{

	}
*/
}