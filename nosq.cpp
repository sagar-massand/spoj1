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

void find_prime(int *prime)
{
	//std::vector<int> prime;
	int i,j,k;
	int *flag=(int *)malloc(1001*sizeof(int));
	for(i=3;i<1000;i+=2)
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
	return prime;
}
void store(std::vector<int> *num,int number)
{
	int final;
	final=number;
	int i,j,k;
	int flag[10];
	FOR(i,10)
	{
		flag[i]=0;
	}
	while(final!=0)
	{
		j=final%10;
		if(flag[j]==0)
		{
			num[j].push_back(number);
			flag[j]=1;
		}
		final/=10;
	}
}
void execute(std::vector<int> *num,std::vector<int> prime)
{
	int temp,i,j,k;
	int *flag=(int *)malloc(100001*sizeof(int));
	ps("Enter")
	FORi(i,1,100000)
	{
		flag[i]=1;
	}
	ps("Then come further")
	for(i=1;prime[i]<320;i++)
	{
		temp=(prime[i]*prime[i]);
		for(j=temp;j<100000;j+=temp)
		{
			flag[j]=0;
		}
	}
	ps("Nearly over")
	for(i=1;i<100000;i++)
	{
		if(flag[i]==1)
		{
			store(num,i);
		}
		if(i%4==3)
			i++;
	}
	ps("Over")
}
int search(int a,int b,std::vector<int> v)
{
	int start,end,mid,ans1,ans2;
	start=0;
	end=v.size()-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid]<a)
		{
			start=mid+1;
		}
		else if(v[mid]>a)
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
	start=0;
	end=v.size()-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid]>b)
		{
			end=mid-1;
		}
		else if(v[mid]<b)
		{
			if(v[mid+1]>a)
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
	return (ans2+1-ans1);
}
int main()
{
	int i,j,k,n,t,ans;
	std::vector<int> num[10];
	std::vector<int> prime;

	prime=find_prime();
	cout<< prime.size()<<endl;
	ps("Hello")
	execute(num,prime);
	si(t)
	FOR(i,t)
	{
		int a,b,d;
		si(a)
		si(b)
		si(d)
		ans=search(a,b,num[d]);
		pi(ans)

	}

}