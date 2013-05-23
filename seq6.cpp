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

int prnt(int *final, int n, int *prime, int total)
{
	int i,j,k,ans=1,flag=0;
	for(i=1;(i<total)&&(prime[i]<=n);i++)
	{
	/*	if(final[i]==0)
			continue;
		else 
		{
			if(flag==0)
			{
				flag=1;
			//	printf("%d",prime[i]);
			}
			else
			{
			//	printf(" * %d",prime[i]);
			}
			FORi(j,1,final[i])
			{
			//	printf(" * %d",prime[i]);
			}
		}*/
		ans*=(final[i]+1);
	}
	return ans;
}

int chk_prime1(int n,int *prime,int total)
{

	int start,end, mid,flag=0,i,j,k;
	if(n<32000)
	{
		
		start=0;
		end=total-1;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(prime[mid]==n)
			{	
				return 1;
			}
			else if(prime[mid]<n)
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		return 0;	
	}
/*	else
	{
		
		for(i=0;(i<total)&&(prime[i]<=sqat);i++)
		{
			if(n%prime[i]==0)
				return 0;
		}
		return 1;
	}
*/	
}

int chk_prime2(int n,int *prime,int total,int sqat)
{

	int start,end, mid,flag=0,i,j,k;
	for(i=0;(i<total)&&(prime[i]<=sqat);i++)
	{
			if(n%prime[i]==0)
				return 0;
	}
	return 1;

/*	int start,end, mid,flag=0,i,j,k;
	if(n<32000)
	{
		
		start=0;
		end=total-1;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(prime[mid]==n)
			{	
				return 1;
			}
			else if(prime[mid]<n)
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		return 0;	
	}
	else
	{
		
		for(i=0;(i<total)&&(prime[i]<=sqat);i++)
		{
			if(n%prime[i]==0)
				return 0;
		}
		return 1;
	}
*/	
}


int main()
{
	int n,i,j,k,total,sqat;
	int *prime, *prim_search;
	prime=(int *)malloc(1000001*sizeof(int));
	prim_search=(int *)malloc(1000001*sizeof(int));
	int flag,flag1;
	FOR(i,32001)
	{
		prim_search[i]=1;
	}
	prim_search[1]=0;
	prime[0]=2;
	k=2;
	prime[1]=3;
	for(i=3;i<174;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			for(j=i*i;j<32000;j+=(2*i))
			{

				prim_search[j]=0;
			}
			k++;
		}
	}
	for(;i<32000;i+=2)
	{
		if(prim_search[i]==1)
		{
			prime[k]=i;
			k++;
		}
	}
	/*for(;i<10000000;i+=2)
	{
		flag=0;
		for(j=0;(prime[j]<32000)&&(j<k);j++)
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
	}*/
	total=k;
	si(n)
	int temp,a,b,c,ans;
	int *final;
	final=(int *)malloc(1000000*sizeof(int));
	while(n!=0)
	{
		temp=n;
		if(n>32000)
		{
			sqat=sqrt(n);
			flag1=chk_prime2(n,prime,total,sqat);
		}
		else
		{
			flag1=chk_prime1(n,prime,total);
			sqat=180;
		}
		if((flag1==1)&&(n!=2))
		{
			ps("4")
		}
		else
		{
			FOR(i,total)
			{
				final[i]=0;
			}
			for(i=0;(i<total)&&(prime[i]<=sqat);i++)
			{
				while(temp%prime[i]==0)
				{
					temp/=prime[i];
					final[i]++;
				}
			}
			//printf("%d = ",n);
			ans=prnt(final,n,prime,total);
			if(temp!=1)
			{
				//printf(" * %d\n",temp);
				ans*=2;
			}
		/*	else
				printf("\n");
		*/	ans*=2;
		//	printf("With %d marbles, %d different rectangles can be constructed.\n",n,ans);
			pi(ans)
		}

		si(n)
	}
	return 0;
}