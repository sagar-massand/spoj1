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
	long long int n,a,b,c,len,i,j,k;
	char ch1[5001],ch2[5001];
	long long ans[5001];
	ss(ch1);
	while(ch1[0]!='0')
	{
		len=strlen(ch1);
		FOR(j,len)
		{
			ch2[len-(j+1)]=ch1[j];
			ans[j]=0;
			//ans[j][1]=0;
		}
		//ans[len]=0;
		if(ch2[0]=='0')
		{
			ans[0]=0;		
		}
		else
		{
			ans[0]=1;
		}


		if(ch2[1]=='0')
		{
			ans[1]=0;
		}
		else if(ch2[1]=='1')
		{
			if(ch2[0]=='0')
			{
				ans[1]=1;
			}
			else
			{
				ans[1]=2;
			}
		}
		else if(ch2[1]=='2')
		{
			if((ch2[0]<='6')&&(ch2[0]>'0'))
			{
				ans[1]=2;
			}
			else //Covering both cases when ch2[0]==0  and ch2[0]>6
			{
				ans[1]=1;
			}
		}
		else
		{
			ans[1]=1;	//Because ch2[0] has to be greater than 0 now.
		}
		//ps(ch2)

		for(j=2;j<len;j++)
		{

			if(ch2[j]=='0')
			{
				ans[j]=0;
			}
			else if(ch2[j]=='1')
			{
			//	ps("I am inside 1 wala loop")
				if(ch2[j-1]=='0')
					ans[j]=ans[j-2];
				else
					ans[j]=ans[j-2]+ans[j-1];
			}
			else if(ch2[j]=='2')
			{
			//	ps("I am inside 2 wala loop")
				if(ch2[j-1]=='0')
				{
			//		ps("I didn't go there")
					ans[j]=ans[j-2];
				}
				else if ((ch2[j-1]<='6')&&(ch2[j-1]>'0'))
				{
			//		ps("I really did go here")
					ans[j]=ans[j-1]+ans[j-2];
				}
				else
				{
			//		ps("I instead went here")
					ans[j]=ans[j-1];
				}
			}
			else
			{
				ans[j]=ans[j-1];
			}
		}
	/*	FOR(j,len)
		{
			printf("Digit is %c\n",ch2[j]);
			pl(ans[j]);
		}
	*/
		pl(ans[len-1])
		ss(ch1)
	}
	return 0;

}