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

class score
{
public:
	int team;
	int time1;
	void initialize(int team1,int minute,int second)
	{
		team=team1;
		time1=(minute*60)+second;
	}	
};

bool compare(score a, score b)
{
	return (a.time1<b.time1);
}

int main()
{
	int n,min,sec,team,i,j,k,score1=0,score2=0,flag=0,timer=0,time1=0,time2=0;
	score num[100];
	si(n)
	FOR(i,n)
	{
		si(team)
		scanf("%d:%d",&min,&sec);
		num[i].initialize(team,min,sec);
	}
	sort(num,num+n,compare);
	FOR(i,n)
	{
		if(flag==1)
		{
			time1+=(num[i].time1-timer);
		}
		else if(flag==2)
		{
			time2+=(num[i].time1-timer);
		}
		timer=num[i].time1;
		if(num[i].team==1)
			score1++;
		else
			score2++;
		if(score1>score2)
			flag=1;
		else if(score2>score1)
			flag=2;
		else
			flag=0;
		//printf("Time1 is %d\n",time1);
		//printf("Time2 is %d\n",time2);
	}
	if(flag==1)
	{
		time1+=(2880-timer);
	}
	else if(flag==2)
	{
		time2+=(2880-timer);
	}	
	min=time1/60;
	sec=time1%60;
	if(min<10)
		printf("0%d:",min);
	else
		printf("%d:",min);
	if(sec<10)
		printf("0%d\n",sec);
	else
		printf("%d\n",sec);
	min=time2/60;
	sec=time2%60;
	if(min<10)
		printf("0%d:",min);
	else
		printf("%d:",min);
	if(sec<10)
		printf("0%d\n",sec);
	else
		printf("%d\n",sec);

	//printf("%d:%d\n",time1/60,time1%60);
	//printf("%d:%d\n",time2/60,time2%60);

	
}