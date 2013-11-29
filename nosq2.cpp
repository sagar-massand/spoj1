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

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define FORi(i,a,b)	for(i=a;i<b;i++)

int find_prime(int *prime)
{
	int i,j,k;
	int flag[1001];
	FOR(i,1000)
	{
		flag[i]=1;
	}
	prime[0]=2;
	k=1;
	for(i=3;i<32;i+=2)
	{
		if(flag[i]==1)
		{
			prime[k]=i;
			k++;
			for(j=i*i;j<1000;j+=(2*i))
			{
				flag[j]=0;
			}
		}
	}
	for(;i<1000;i+=2)
	{
		if(flag[i]==1)
		{
			prime[k]=i;
			k++;
		}
	}
	return k;
}
void store(int **num,int *num_size,int number)
{
	int final=number;
	int i,j,k;
	int flag[10];
	FOR(i,10)
		flag[i]=0;
	while(final!=0)
	{
		j=final%10;
		if(flag[j]==0)
		{
			num[j][num_size[j]]=number;
			num_size[j]++;
			flag[j]=1;
		}
		final/=10;
	}
}
void execute(int **num,int *num_size,int *prime)
{
	int *flag=(int *)malloc(100001*sizeof(int));
	int temp,i,j,k;
	FOR(i,100000)
	{
		flag[i]=1;
	}
	for(i=1;prime[i]<320;i++)
	{
		temp=prime[i]*prime[i];
		for(j=temp;j<100000;j+=temp)
		{
			flag[j]=0;
		}
	}
	for(i=1;i<100000;i++)
	{
		if(flag[i]==1)
		{
			store(num,num_size,i);
		}
		if(i%4==3)
			i++;
	}
}

int search(int a,int b,int *v,int size)
{
	int start,end,mid,ans1,ans2;
	start=0;
	end=size-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid]<a)
		{
			start=mid+1;
		}
		else if(v[mid]>a)
		{
			if(mid>0)
			{
				if(v[mid-1]<a)
				{
					ans1=mid;
					break;
				}
				else
				{
					end=mid-1;
				}
			}
			else
			{
				ans1=mid;
				break;
			}
		}
		else
		{
			ans1=mid;
			break;
		}
	}
	start=0;
	end=size-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid]>b)
		{
			end=mid-1;
		}
		else if(v[mid]<b)
		{
			if(mid+1<size)
			{
				if(v[mid+1]>b)
				{
					ans2=mid;
					break;
				}
				else
				{
					start=mid+1;
				}
			}
			else
			{
				ans2=mid;
				break;
			}
		}
		else
		{
			ans2=mid;
			break;
		}
	}
	return (ans2+1-ans1);
}
int main()
{
	int t,i,j,k,prime_size;
	int prime[300];
	int *num[10];
	int num_size[10];
	FOR(i,10)
	{
		num_size[i]=0;
	}
	prime_size=find_prime(prime);
	execute(num,num_size,prime);
	si(t)
	FOR(i,t)
	{
		int a,b,d,ans;
		si(a)
		si(b)
		si(d)
		ans=search(a,b,num[d],num_size[d]);
		pi(ans)
	}
}