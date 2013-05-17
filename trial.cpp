#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);


class pos
{
public:
	long long ref;
	long long area;
	void initialize(int a,int b)
	{
		ref=a;
		area=b;
	}
	void add(int a)
	{
		area+=a;
	}

};
bool compare(pos a,pos b)
{
	return (a.ref<b.ref);
}
int main()
{
	long long n,i,j,k,sum,flag=0,count;
	short int ans[1000000];
	long long a[1000000];
	sl(n)


	return 0;
}