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
	long long t,i,j,k;
	sl(t)
	FOR(i,t)
	{
		double keeper_x,keeper_y,ball_x,ball_y,goal_y1=-3.66,goal_y2=3.66,goal_x=52.5,radius,m,flag=0,final;
		sf(ball_x)
		sf(ball_y)
		sf(keeper_x)
		sf(keeper_y)
		sf(radius)
		
			//y-goal_y=((goal_y-ball_y)/(goal_x-ball_x))(x-goal_x)
		m=((goal_y1-ball_y)/(goal_x-ball_x));
			//final=y-mx+m*goal_x-goal_y
		final=keeper_y+(m*goal_x)-((m*keeper_x)+goal_y1);
		if(final<0)
			final=(-1*final);
		final/=sqrt(m*m+1);
		if(final>=radius)
			flag=1;
		else
		{
			m=((goal_y2-ball_y)/(goal_x-ball_x));
			final=keeper_y+(m*goal_x)-((m*keeper_x)+goal_y2);
			if(final<0)
				final=(-1*final);
			final/=sqrt(m*m+1);
			if(final>=radius)
				flag=1;
		}
		if(flag==1)
			ps("Goal!")
		else
			ps("No goal...")

	}
	return 0;
}