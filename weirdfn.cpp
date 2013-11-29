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

class numb
{
public:
	unsigned long long value;
	void initialize(int a)
	{
		value=a;
	}
};

bool operator <(numb a,numb b)
{
	return (a.value>b.value);
}

int main()
{
	numb fin;
	unsigned long long a,b,c,n,t,sum,temp,temp2,funk,num_prev;
	long long temp_prev;
	unsigned long long i,j,k;
	int z1,z2,z3,z4;
	scanf("%d",&z1);
	t=z1;
	FOR(i,t)
	{
		priority_queue <numb> MaxQ;
		priority_queue <unsigned long long> MinQ;
		scanf("%d%d%d%d",&z1,&z2,&z3,&z4);
		a=z1;
		b=z2;
		c=z3;
		n=z4;
		sum=1;
		MinQ.push(1);
		funk=b+c;
		temp_prev=1;
		//num_prev=a;
		//temp_prev=1;
		FORi(j,2,n+1)
		{
			temp=MinQ.top();
			funk+=b;
		//	if(temp_prev!=temp)
		//		num_prev=a*temp;
			temp2=(a*temp+funk)%mod;
		//	temp_prev=temp;
			//pl(temp2)
			sum+=temp2;
			//sum%=mod;
			/*if(temp2>temp)
			{
				fin.initialize(temp2);
				MaxQ.push(temp2);
			}
			else
			{

			}
			*/
		/*	if(j%2==0)
			{
				if(temp2>temp)
				{
					fin.initialize(temp2);
					MaxQ.push(fin);
				}
				else
				{
					MinQ.pop();
					MinQ.push(temp2);
					fin.initialize(temp);
					MaxQ.push(fin);
				}
			}
			else
			{
				if(temp2>temp)
				{
					fin=MaxQ.top();
					MaxQ.pop();
					MinQ.push(fin.value);
					fin.initialize(temp2);
					MaxQ.push(fin);
				}
				else
				{
					MinQ.push(temp2);
				}
			}
		}*/
			if(temp2>temp)
			{
				fin.initialize(temp2);
				MaxQ.push(fin);
				temp_prev--;
				//ps("Hi")
			}
			else
			{
				MinQ.push(temp2);
				temp_prev++;
				//ps("NOt")
			}
	//		printf("%llu\n",temp_prev);
			if(temp_prev<0)
			{
				fin=MaxQ.top();
				MaxQ.pop();
				MinQ.push(fin.value);
				temp_prev+=2;
				//ps("Got")
			}
			else if(temp_prev>1)
			{
				temp2=MinQ.top();
				MinQ.pop();
				fin.initialize(temp2);
				MaxQ.push(fin);
				temp_prev-=2;
				//ps("dsddd")
			}
		}
		//sum+=((n*c)%mod);
		//sum%=mod;
		printf("%llu\n",sum);	
	}
	return 0;
}