#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
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

#define FORi(i,a,n)	for(i=a;i<n;i++)

long long increase(char *ch,long long j,long long len)
{
	long long k,flag=0,temp=(len-1)/2;
	while(temp>j)
	{
		if(ch[temp]!='9')
		{
			ch[temp]++;
			//ch[len-(temp+1)]++;
			ch[len-(temp+1)]=ch[temp];
			flag=1;
			return flag;
		//	break;
		}
		else
		{
			ch[temp]='0';
			ch[len-(temp+1)]='0';
			temp--;
		}
	}
	return 0;
	/*if(flag==0)
	{
		ch[j]++;
		ch[len-(j+1)]=ch[j];
	}*/

}
int main()
{
	char *ch;
	ch=(char *)malloc(1000004*sizeof(char));
	long long t,i,j,k,len,a,b,c,flag,flag1;

	sl(t);
	FOR(i,t)
	{
		flag=0,flag1=0;
		ss(ch);
		len=strlen(ch);
		for(j=(len-1)/2;j>=0;)
		{
			k=len-(j+1);
			if(ch[j]==ch[k])
			{
				j--;
			}
			else if(ch[j]<ch[k])
			{
				flag1=increase(ch,j,len);
				//pl(flag1)
				if(flag1==0)
				{
					ch[j]++;
					ch[len-(j+1)]=ch[j];
				}
				else
				{
					ch[len-(j+1)]=ch[j];
				}
				flag=1;
				break;
			}
			else
			{
				ch[k]=ch[j];
				flag=2;
				break;
			}
		}
		if(flag==0)
		{
			flag1=increase(ch,0,len);
			if(flag1==0)
			{
				if(ch[0]!='9')
				{
					ch[0]++;
					ch[len-1]=ch[0];
					ps(ch)
				}
				else
				{
					printf("1");
					FOR(a,len-1)
					{
						printf("0");
					}
					ps("1")
				}
			}
			else
			{

				ps(ch)
			}
		}
		else
		{
			for(a=j-1;a>=0;a--)
			{
				ch[len-(a+1)]=ch[a];
			}
			ps(ch)

		}
		
	}
	return 0;
}