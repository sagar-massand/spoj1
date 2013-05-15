#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

int main()
{
	int a,b,c,i,j,k,t,len1,len2,find_max,min;
	char ch1[2000],ch2[2000],ans[2000];
	si(t)
	FOR(i,t)
	{
		ss(ch1)
		ss(ch2)
		len1=strlen(ch1);
		len2=strlen(ch2);
		if(len1<len2)
			min=len1;
		else
			min=len2;
		find_max=0;
		FOR(j,min)
		{
			if(ch1[j]==ch2[j])
			{
				if(ch1[j]=='1')
				{
					ans[j]='1';
					find_max=j;
				}	
				else
					ans[j]='0';
			}
			else
				ans[j]='0';
		}

		if((find_max==0)&&(ans[0]=='0'))
			ps("relatively prime")
		else
		{
			FOR(j,find_max+1)
			{
				printf("%c",ans[j]);
			}
			printf("\n");
		}
	}
}