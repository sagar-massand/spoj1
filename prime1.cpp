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
	int *prime, *prim_search;
	prime=(int *)malloc(1000000*sizeof(int));
	prim_search=(int *)malloc(1000000*sizeof(int));
	int i,j,k,a,b,c,total,start,end,t,sqat,flag;
	FOR(i,1000000)
	{
		prim_search[i]=1;
	}
	prim_search[1]=0;
	prime[0]=2;
	prime[1]=3;
	k=2;
	for(i=3;i<1000;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			for(j=i*i;j<=1000000;j+=(2*i))
			{
				prim_search[j]=0;
			}
			k++;
		}
	}	
	for(;i<1000000;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			k++;
		}
	}
	total=k;
	//pi(total)
	si(t)
	FOR(i,t)
	{
		si(start)
		si(end)
		sqat=sqrt(end);
		j=start;
		if((j<=2)&&(end>1))
		{
			ps("2")
			if(j%2==0)
				j++;
			for(;(j<=end)&&(j<1000000);j+=2)
			{
				if(prim_search[j]==1)
					pi(j);
			}
		}
		else if(end==1)
			continue;
		else 
		{
			if(j%2==0)
				j++;

		}
		for(;j<=end;j+=2)
		{
			flag=0;
			for(k=0;((k<total)&&(prime[k]<=sqat)&&(prime[k]<=j));k++)
			{
				if(j%prime[k]==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				pi(j);
		}
		
	}
	return 0;
}