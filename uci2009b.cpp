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

int total;
int *prime;

void add(int *final,int *a)
{
	int i;
	FOR(i,total)
	{
		final[i]+=a[i];
	}
}

void subt(int *final,int *a)
{
	int i;
	FOR(i,total)
	{
		final[i]-=a[i];
	}
}

void prnt(char ch, int num)
{
	if(num==1)
		printf("%c",ch);
	else if(num>1)
	{
		printf("%c^%d",ch,num);
	}
}

void pr(int *final)
{
	int i;
	FOR(i,total)
	{
		if(final[i]==1)
		{
			printf("%dx",prime[i]);
		}
		else if(final[i]>1)
		{
			printf("%d^%dx",prime[i],final[i]);
		}
	}
}

int main()
{
	
	int **num;
	int i,j,k,flag,a,b,c,flag1,temp;
	int ans,r;
	int *final;
	int t,n;
	prime=(int *)malloc(1001*sizeof(int));
	final=(int *)malloc(1001*sizeof(int));
	num=(int **)malloc(1001*sizeof(int *));
//	ps("1 in")
	FOR(i,1001)
	{
		
		num[i]=(int *)malloc(1001*sizeof(int));
	}
//	ps("2 in")
	FOR(i,1001)
	{
		FOR(j,1001)
		{
			num[i][j]=0;
		}
	}
//	ps("3 in")
	prime[0]=2;
	prime[1]=3;
	k=2;
	for(i=5;i<1000;i+=2)
	{
		flag=0;
		for(j=0;j<k;j++)
		{
			if(i%prime[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			prime[k]=i;
			k++;
		}
	}
//	ps("4 in")
	total=k;
//	pi(total)

	for(i=2;i<=1000;i++)
	{
		temp=i;
		for(j=0;(j<total)&&(prime[j]<=temp);j++)
		{
			while(temp%prime[j]==0)
			{
				temp/=prime[j];
				num[i][j]++;
			}
		}
	}

/*	for(i=2;i<=1000;i++)
	{
		//ps("I was here")
		for(j=0;(j<total)&&(prime[j]<=i);j++)
		{
			printf("i is %d while j is %d\n",i,j);
			pi(prime[j])

			//ps("Not now")
			while((i%prime[j])==0)
			{
				ps("I even went here")
				
				i=(i/prime[j]);
				num[i][j]++;
			}
		}
	}
*/
//	ps("5 in")
	si(t)
	FOR(i,t)
	{
		ans=1;
		FOR(j,total)
		{
			final[j]=0;
		}
		si(n)
		if(n==0)
		{
			ps("1")
			continue;
		}
		else
		{

			prnt('A',n);
			FORi(r,1,n+1)
			{
				printf("+");
				add(final,num[n-r+1]);
				subt(final,num[r]);
				pr(final);
				prnt('A',n-r);
				prnt('B',r);
				
			}
			printf("\n");
			
		}
	}
	return 0;
}