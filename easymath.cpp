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

long long find_lcm(long long a,long long b)
{
	long long x,y,z,temp;
	x=a;
	y=b;
	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	z=x%y;
	while(z!=0)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return ((a*b)/y);
}

long long find_lcm1(long long a,long long b,long long c)
{
	long long temp,ans;
	temp=find_lcm(a,b);
	ans=find_lcm(temp,c);
	return ans;
}

long long find_lcm2(long long a,long long b,long long c,long long d)
{
	long long temp;
	temp=find_lcm(a,b);
	temp=find_lcm(temp,c);
	temp=find_lcm(temp,d);
	return temp;
}

int main()
{
	long long n,m,a,d,temp,t,ans,i,j,k,num[5],lcm,x,y,z,final;
	sl(t)
	FOR(i,t)
	{
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&a,&d);
		num[0]=a;
		num[1]=a+d;
		num[2]=a+2*d;
		num[3]=a+3*d;
		num[4]=a+4*d;
		z=n-1;
	//	temp=a;
		FOR(j,5)
		{
			ans+=(m+1-(n+((m/num[j])-(z/num[j]))));
		}
		FOR(j,4)
		{
			FORi(k,j+1,5)
			{
				temp=find_lcm(num[j],num[k]);
				ans-=(m+1-(n+((m/temp)-(z/temp))));
			}
		}
		FOR(j,3)
		{
			FORi(k,j+1,4)
			{
				FORi(x,k+1,5)
				{
					temp=find_lcm1(num[j],num[k],num[x]);
					ans+=(m+1-(n+((m/temp)-(z/temp))));
				}
			}
		}
		FOR(j,2)
		{
			FORi(k,j+1,3)
			{
				FORi(x,k+1,4)
				{
					FORi(y,x+1,5)
					{
						temp=find_lcm2(num[j],num[k],num[x],num[y]);
						ans-=(m+1-(n+((m/temp)-(z/temp))));
					}
				}
			}
		}
		temp=find_lcm(find_lcm2(num[0],num[1],num[2],num[3]),num[4]);
		ans+=(m+1-(n+((m/temp)-(z/temp))));
		pl(ans)
	}	
}