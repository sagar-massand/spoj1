//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>
#include<string.h>
//#include<math.h>
//#include<queue>
//#include<vector>
//#include<stack>
//#include<set>
//using namespace std;

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

#define mynum 255255

#define FORi(i,a,n)	for(i=a;i<n;i++)

int main()
{
	int a,b,c,i,j,k,total,fin;
	int *prime;
	//int num[24]={2,4,8,16,22,26,32,34,38,44,46,52,58,62,64,68,74,76,82,86,88,92,94,104}
	int *pum;
	pum=(int *)malloc(100000*sizeof(int));
	char *prim;
	prime=(int *)malloc(5000100*sizeof(int));
	prim=(char *)malloc(86028130*sizeof(char));
	//printf("%c\t%c\t%c\n",prim[0],prim[1],prim[2]);
	/*for(i=3;i<100000000;i+=2)
	{
		prim[i]='1';
	}*/
	a=0;
	for(b=2;b<2*mynum;b+=2)
	{
		if(b%3!=0)
		{
			if(b%5!=0)
			{
				if(b%7!=0)
				{
					if(b%11!=0)
					{
						if(b%13!=0)
						{
							if(b%17!=0)
							{
								pum[a]=b;
								a++;
							}
						}
					}
				}
			}
		}
	}
	fin=a;
	pi(fin)
	prime[0]=2;
	k=1;
	for(i=3;i<10000;i+=2)
	{
		if(prim[i]!='0')
		{
			prime[k]=i;
			k++;
			for(j=i*i;j<86028130;j+=2*i)
			{
				prim[j]='0';
			}
		}
	}
//	ps("I am here")
	for(;i%mynum!=0;i+=2)
	{
		if(prim[i]!='0')
		{
			prime[k]=i;
			k++;
		}
	}
	//ps("Even here")
	for(;(i<86028130);i+=(2*mynum))
	{
		for(a=0;a<fin;a++)
		{
			j=i+pum[a];		
			if((prim[j]!='0')&&(j<86028130))
			{
				prime[k]=j;
				k++;
			}
		}
	}
	//ps("Not here")
	//total=k;
	int n,current;
	si(n)
	FOR(i,n)
	{
		si(current)
		pi(prime[current-1])
	}
	return 0;
}