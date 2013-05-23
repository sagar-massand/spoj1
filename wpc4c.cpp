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

long long power(long long a, long long b)
{
	long long ans;
	if(b>1)
	{
		ans=power(a,b/2);
		if(b%2==1)
			return (ans*ans*a);
		else
			return (ans*ans);
	}
	else if(b==1)
		return a;
	else
		return 1;
}

long long find_log(long long n)
{
	long long i=0;
	n/=2;
	while(n!=0)
	{
		n/=2;
		i++;
	}
	return i;
}

int chk_possible1(long long a,long long b)
{
	long long ans;
	double num;
	num=b;
	num*=0.8;
	ans=ceil(num);
	if(a>=ans)
		return 1;
	else
		return 0;
}

int main()
{
	long long t,i,j,k;
	long long height,width,area,final_height,final_width;
	long long logheight,logwidth,minlog,trial,testheight,testwidth;
	int flag=0,ans;
	sl(t)
	FOR(i,t)
	{
		ans=0;
		sl(height)
		sl(width)
		if(height<width)
			flag=0;
		else
			flag=1;
		logheight=find_log(height);
		logwidth=find_log(width);
		if(logheight>logwidth)
			minlog=logwidth;
		else
			minlog=logheight;
		trial=power(2,minlog+1);
		if(flag==0)
		{
			if(trial<=width)
			{
				ans=chk_possible1(height,trial);
				if(ans==1)
				{
					final_height=height;
					final_width=trial;
					printf("%lld %lld\n",final_height,final_width);
					continue;
				}
			}
			trial/=2;
	//		if(trial<=height)	//Redundant statement. trial always<=height
	//		{
			final_height=trial;
			final_width=min(((5*trial)/4),width);
			testheight=min(height,((5*trial)/4));
			if(testheight>=final_width)
			{
				final_height=testheight;
				final_width=trial;
				
			}
			printf("%lld %lld\n",final_height,final_width);
			continue;


	//		}

		}
		else
		{
			if(trial<=height)
			{
				ans=chk_possible1(width,trial);
				if(ans==1)
				{
					final_height=trial;
					final_width=width;
					printf("%lld %lld\n",final_height,final_width);
					continue;
				}
			}
			trial/=2;
		//	if(trial<=width)	//Redundant statement. trial always<=width
		//	{
			final_width=trial;
			final_height=min(((5*trial)/4),height);
			printf("%lld %lld\n",final_height,final_width);
			continue;
				/*testheight=min(height,((5*trial)/4))
				if(testheight>=final_width)
				{
					final_height=testheight;
					final_width=trial;
					printf("%lld %lld\n",final_height,final_width);
					continue;

				}*/
		//	}
		}

	}
	return 0;
}