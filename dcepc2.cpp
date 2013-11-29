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

//This is the code for dcepc702

int main()
{
	long long i,j,k,t;
	sl(t)
	FOR(i,t)
	{
		// The formula:(1-x^a)(1-x^b)(1-x^c)/(1-x)^3
		// where a=maxa+1-mina
		long long mina,minb,minc,maxa,maxb,maxc,a,b,c,ans=0,temper,temper2;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&mina,&maxa,&minb,&maxb,&minc,&maxc);
		n-=(mina+minb+minc);
		a=(maxa+1-mina);
		b=(maxb+1-minb);
		c=(maxc+1-minc);
		long long power[8];
		long long temp[8];
		power[0]=0;
		power[1]=a;
		power[2]=b;
		power[3]=c;
		power[4]=a+b;
		power[5]=b+c;
		power[6]=a+c;
		power[7]=a+b+c;
		temp[0]=1;
		temp[1]=-1;
		temp[2]=-1;
		temp[3]=-1;
		temp[4]=1;
		temp[5]=1;
		temp[6]=1;
		temp[7]=-1;
		FOR(j,8)
		{
			if(power[j]<=n)
			{
				temper=(n-power[j]);
				temper2=((temper+1)(temper+2))/2;
				temper2%=mod;
				ans+=temper2;
				ans%=mod;
			}
		}



	}

}
