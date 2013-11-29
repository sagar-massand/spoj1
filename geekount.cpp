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

int find_index(char *ch1,char *ch2,int len)
{
	int i;
	FOR(i,len)
	{
		if(ch1[i]!=ch2[i])
			return i;
	}
}

int check_current(char *ch)
{
	FOR(i,len)
	{
		if((ch[i]-'0')%2==0)
			return 0;
	}
	return 1;
}

void find_next(char *ch,int len)
{
	int i,flag=0;
	FOR(i,len)
	{
		if((ch[i]-'0')%2==0)
		{
			ch[i]++;
		//	flag=1;
			i++;
			break;
		}
	}
	for(;i<len;i++)
	{
		ch[i]='1'
	}
}

int find_value(char *start,char *end,int len)
{
	int index,flag,i,j,k,ans=0,temp=1;
	index=find_index(start,end,len);
	flag=check_current(start,len);
	if(flag==0)
	{
		find_next(start,len);
	}
	if(!is_less(start,end))
		return 0;
	else
	{
		ans=1;
		//start[j]++;
		for(j=len-1;j>index;j--)
		{
			ans+=(('9'-start[j])/2)*temp);
			start[j]='1';	
			temp*=5;
		}
	}
	start[index]+=2;
	ans++;
	temp=1;
	for(j=len-1;j>=index;j--)
	{
		ans+=(((end[j]-start[j])/2)*temp);
		start[j]=end[j];
		temp*=5;
	}
	return ans;
}
int find(char *start,)
int main()
{
	int i,j,k,t,len1,len2,flag,index,ans;
	si(t)
	char start[15],end[15],temp[15];
	FOR(i,t)
	{
		ans=0;
		ss(start)
		ss(end)
		len1=strlen(start);
		len2=strlen(end);
		if(len1==len2)
		{
			ans=find_value(start,end,len1)
		}
		while(len1<len2)
		{
			ans+=find(start,len1);
			len1++;
		}
		ans+=find_value(start,end,len1);
	}
}