#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

long long calculate(long long sum,long long * count)
{
	long long ans=1,i,j,k;

	for(i=0;i<26;i++)
	{
		if((sum==count[i])||(sum==0))
			return ans;
		else
		{
			if(count[i]>0)
			{
				for(j=sum;j>sum-count[i];j--)
				{
					ans*=j;
				}
				for(j=2;j<=count[i];j++)
				{
					ans/=j;
				}
				sum=sum-count[i];
				count[i]=0;
			}

		}
	}
	return ans;
}

int main()
{
	char an[1000000];
	char ch;
	long long i,j,k,a,b,c,count[26],flag,sum,flag1=0,ans;
	while(gets(an))
	{
		FOR(i,26)
		{
			count[i]=0;
		}
		flag=0;
		sum=0;
		flag1=0;
		for(i=0;an[i]!='\0';i++)
		{
			if((an[i]>='a')&&(an[i]<='z'))
			{
				count[an[i]-'a']++;
			}
			else if ((an[i]>='A')&&(an[i]<='Z'))
			{
				count[an[i]-'A']++;
			}

		}
		FOR(i,26)
		{
			if(count[i]%2==0)
			{
				count[i]/=2;
				sum+=count[i];
			}
			else
			{
				if(flag==0)
				{
					flag=1;
					count[i]/=2;
					sum+=count[i];
				}
				else
				{
					flag=2;
					ps("0")
					break;
				}
			}
		//	ch='a'+i;
		//	printf("The value of count[%c] is %lld\n",ch,count[i]);
		}

		if(flag<2)
		{
			if(sum==0)
			{
				ps("1")
			}
			else
			{
				ans=calculate(sum,count);
				pl(ans);
			}
		}

	}
	return 0;
}