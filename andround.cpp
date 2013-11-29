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

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)


long long find_bits(long long max)
{
	long long i=0,j,k;
	while(max!=0)
	{
		max/=2;
		i++;
	}
	return i;
}

long long find_power(long long n)
{
	long long i,j,k;
	i=1;
	n--;
	while(n>0)
	{
		n/=2;
		i*=2;
	}
	return i;
}

long long initialize(std::vector<long long> num,long long num_bits,long long  n,std::vector<long long> *v)
{
	long long power,i,j,k;
	power=find_power(n);
	k=power-1;
	FOR(i,num_bits)
	{
		FOR(j,power-1)
		{
			v[i].push_back(1);
		}
		FORi(j,k,k+n)
		{
			v[i].push_back((num[j-k]%2));
			num[j-k]/=2;
		}
	}
	return power;
}

void change(long long start, long long end,long long number_bit,long long power,long long n, std::vector<long long> *v)
{
	long long i,j,k;
	printf("Number_bit is %lld  while start is %lld and end is %lld\n",number_bit,start,end);
	if(start<=end)
	{
		start+=(power-1);
		end+=(power-1);
		v[number_bit][start]=0;
		v[number_bit][end]=0;
		ps("")
		pl(start)
		pl(end)
	//	ps("I am in change")
		while(((start-1)/2)!=((end-1)/2))
		{
			if(start%2==1)
				v[number_bit][start+1]=0;
			if(end%2==0)
				v[number_bit][end-1]=0;
			start=((start-1)/2);
			end=((end-1)/2);
	//		printf("Start is %lld while end is %lld\n",start,end);
		}
	//	ps("And here goes")
	/*	FOR(j,power+n)
		{
			pl(v[number_bit][j])
		}
		ps("Here ends")
	*///	ps("I am still in change")
	}
	else
	{
		change(start,n-1,number_bit,power,n,v);
		change(0,end,number_bit,power,n,v);
	}
}

void modify(long long power,int num_bits,long long n,long long cha,std::vector<long long> *v)
{
	long long i,j,k=power-1,temp;
	FOR(i,num_bits)
	{
		FORi(j,k,k+n)
		{
			if(v[i][j]==0)
			{
				temp=j-k;
				//change((j+n-k)%n,(j+k)%n,i,power,n,v);
				//if(((j-cha)<k)
				//change((j+n-(k+cha))%n,(j+cha-k)%n,i,power,n,v);
				pl((temp+n-cha)%n)
				pl((temp+cha)%n)
				change((temp+n-cha)%n,(temp+cha)%n,i,power,n,v);
			}
		}
	}
}
void print(long long power,long long num_bits,long long n,std::vector<long long> *v)
{
	long long i,j,k;
	for(i=0;i<(power+n-1);i++)
	{
		for(j=0;j<num_bits;j++)
		{
			printf("%lld ",v[j][i]);
		}
		printf("\n");
	}
	ps("\n\n")
}
void print_num(long long power,long long num_bits,long long n,std::vector<long long> *v)
{
	long long a,b,c,temp,start,flag;
	FOR(a,n-1)
	{
		temp=0;
		for(b=num_bits-1;b>=0;b--)
		{
			//ps("Ho")
			temp*=2;
			flag=1;
			start=(a+power-1);
			while(start>0)
			{
			//	ps("Bye")
				if(v[b][start]==0)
				{
					flag=0;
					break;
				}
				start=(start-1)/2;
			}
			if(v[b][start]==0)
				flag=0;
			temp+=flag;
		}
		printf("%lld ",temp);
	}
	temp=0;
	for(b=num_bits-1;b>=0;b--)
	{
		temp*=2;
		flag=1;
		start=(a+power-1);
		while(start>0)
		{
			if(v[b][start]==0)
			{
				flag=0;
				break;
			}
			start=(start-1)/2;
		}
		temp+=flag;
	}
	printf("%lld\n",temp);
}

int main()
{
	long long t,i,j,k,n,a,b,c,temp,max;
	sl(t)
	FOR(i,t)
	{
		std::vector<long long> num;
		std::vector<long long> v[32];
		long long num_bits;
		max=0;
	//	num.clear();
/*		FOR(j,32)
		{
			if(v[j].size())
				v[j].clear();
		}
*/		sl(n)
		sl(k)
		FOR(j,n)
		{
			sl(temp)
			if(max<temp)
				max=temp;
			num.push_back(temp);
		}
		if(k>=(n/2))
		{
			temp=num[0];
			FORi(j,1,n)
			{
				temp=(temp&num[j]);
			}
			FOR(j,n-1)
			{
				printf("%lld ",temp);
			}
			printf("%lld\n",temp);
		}
		else
		{
			long long power;
			//int **tree1;
			num_bits=find_bits(max);
		//	ps("I am here")
			power=initialize(num,num_bits,n,v);
		//	ps("I am still here")
			print(power,num_bits,n,v);
			modify(power,num_bits,n,k,v);
		//	ps("I have crossed it")
			print(power,num_bits,n,v);
			print_num(power,num_bits,n,v);
		//	ps("i did it")
		}
	}

}