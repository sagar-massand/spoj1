#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
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
	long long t,i,j,k,n,sqat,sqat2;
	long long last2[100];
	std::vector<long long> v[100];
	FOR(i,100)
	{
		last2[i]=0;
	}
	FOR(i,100)
	{
		for(j=i;j<100;j++)
		{
			sqat=(i*i+j*j)%100;
			last2[sqat]=1;
			v[sqat].push_back(i);
		}
	}
	sl(t)
	FOR(i,t)
	{
		long long temp1,temp2,flag=0,fin,temp3;
		long long a,b,c;
		sl(n)
		sqat=sqrt(n);
		temp1=n%100;
		if(last2[temp1]==1)
		{
		//	ps("I got here")
			FOR(j,v[temp1].size())
			{
		//		ps("even here")
				temp2=v[temp1][j];
		//		pl(temp2)
				for(a=temp2;a<=sqat;a+=10)
				{
					temp3=n-(a*a);
					sqat2=sqrt(temp3);
					if(sqat2*sqat2==temp3)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				ps("YES")
			else
				ps("NO")
		}
		else
			ps("NO")
	}
}