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

#define FORi(i,a,b)	for(i=a;i<b;i++)

int main()
{
	long long i,j,k,n,t,min_a,max_a,min_b,max_b,min_c,max_c,ans;
	sl(t)
	FOR(i,t)
	{
		ans=0;
		//n+r-1Cr-formula
		long long temp[8];
		long long gr1,gr2;
		long long power[8];
		sl(n)
		sl(min_a)
		sl(max_a)
		sl(min_b)
		sl(max_b)
		sl(min_c)
		sl(max_c)
		n-=(min_a+min_b+min_c);
		max_a-=min_a;
		max_b-=min_b;
		max_c-=min_c;
		power[0]=0;
		power[1]=(max_a+1);
		power[2]=(max_b+1);
		power[3]=(max_c+1);
		power[4]=(max_b+max_c+2);
		power[5]=(max_a+max_c+2);
		power[6]=(max_a+max_b+2);
		power[7]=(max_a+max_b+max_c+3);
		temp[0]=1;
		temp[1]=-1;
		temp[2]=-1;
		temp[3]=-1;
		temp[4]=1;
		temp[5]=1;
		temp[6]=1;
		temp[7]=-1;
	//	printf("n is %lld while power[0] is %lld\n",n,power[0]);
		FOR(j,8)
		{
			if(power[j]<=n)
			{
				gr1=(n-power[j]);
				//comb(tempo+2,tempo);
				gr2=((gr1+1)*(gr1+2))/2;
			//	gr2*=(gr1+2);
			//	gr2/=2;
				gr2%=mod;
				gr2*=temp[j];
				gr2+=mod;
				gr2%=mod;
			//	printf("j is %lld while gr2 is %lld\n",j,gr2);
				ans+=gr2;
			//	printf("ans is %lld\n",ans);
				ans%=mod;
			}
		}
		pl(ans)
	}
}
