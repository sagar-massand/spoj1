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

long long find_gcd(long long a,long long b)
{
	long long temp,gcd,rem;
	if(a<b)
	{
		temp=b;
		b=a;
		a=temp;
	}
	rem=a%b;
	while(rem!=0)
	{
		a=b;
		b=rem;
		rem=a%b;
	}
	//pl(b)
	return b;


}

int main()
{
	long long i,j,k,n,size1,size2,value1,value2,lcm,gcd,fin_value,t,num1,num2,g1,g2,temp,temp_value,max_value,temp1;
	sl(t)
	long long divi;
	FORi(i,1,t+1)
	{
		sl(n)
		sl(size1)
		sl(value1)
		sl(size2)
		sl(value2)
		
		fin_value=0;
		gcd=find_gcd(size1,size2);
		//printf("gcd is %lld\n",gcd);
		lcm=((size1*size2)/gcd);
		num1=lcm/size1;
		num2=lcm/size2;
		g1=num1*value1;
		g2=num2*value2;
		//printf("num1 is %lld\n",num1);
		//printf("num2 is %lld\n",num2);
		//printf("g1 is %lld\n",g1);
		//printf("g2 is %lld\n",g2);
		divi=n/lcm;
		if(divi>1)
			divi--;
		else
			divi=0;
		if(g1>=g2)
		{
			fin_value=g1*divi;
		}
		else
		{
			fin_value=g2*divi;
		}
		//printf("fin_value is %lld\n",fin_value);
		temp1=n-(divi*lcm);
		//pl(n)
		max_value=0;
		if(size1>size2)
		{
		//	ps("Size1>size2")
			//max_value=(n/size2)*value2;
			for(j=0;(j*size1)<=temp1;j++)
			{
				temp=(temp1-(j*size1));
				temp_value=(j*value1)+((temp/size2)*value2);
				if(temp_value>max_value)
				{
					max_value=temp_value;
				}
			}
		}
		else
		{
			//max_value=(n/size1)*value1;
			for(j=0;(j*size2)<=temp1;j++)
			{
				temp=(temp1-(j*size2));
				temp_value=(j*value2)+((temp/size1)*value1);
				if(temp_value>max_value)
				{
					max_value=temp_value;
				}
			}
		}
		fin_value+=max_value;
		printf("Case #%lld: %lld\n",i,fin_value);
			
		
	/*	else
		{
			printf("Case #%lld: 0\n",i);
		}
	*/
	}
	return 0;
}