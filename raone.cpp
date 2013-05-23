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

int find_diff(int n)
{
	int i,ans=0;
	for(i=1;n!=0;i++)
	{
		if(i%2==0)
		{
			ans+=(n%10);
		}
		else
			ans-=(n%10);
		n/=10;
	}
	return ans;
}

int ra(int num1,int num2)
{
	int a[100],comp[40],compute[20];
	int len1,len2,ans=0,i,j,k,p1,p2;
	//len1=strlen(ch1);

	//len2=strlen(ch2);
	//if(len1%2==0)
	for(i=0;i<=9;i++)
	{
		//((1-x^10)(1-x)^-1)^2=(n+1C1)-(n-9C1)(2C1)=19-n(ifn>=10),n+1(if n<=9)
		comp[i]=(i+1);
		//a[i]=compute(18-i);
		//a[36-i]=a[i];
	}
	for(;i<=18;i++)
	{
		comp[i]=19-i;
	}
	for(i=0;i<=18;i++)
	{
		compute[i]=0;
		for(j=i;j<=18;j++)
		{
			compute[i]+=(comp[j]*comp[j-i]);
		}
	}
	len1=(num1/10000);
	len2=(num2/10000);
	ans=0;
	FORi(i,len1+1,len2)
	{
		p1=find_diff(i);
		if((p1>=1)&&(p1<20))
			ans+=compute[p1-1];
		else if((p1>=-17)&&(p1<1))
			ans+=compute[1-p1];
		else
			ans+=0;

	}
	
	if(len1!=len2)
	{
		i=num1;
		i+=(10-(i%11));
		for(;(i/10000)==len1;i+=11)
		{
			if(find_diff(i)==1)
				ans++;
			//ps("I was here")
		}

		i=len2*10000;
		i+=(10-(i%11));
		for(;i<=num2;i+=11)
		{
			if(find_diff(i)==1)
				ans++;
		}
	}
	else
	{
		i=num1;
		i+=(10-(i%11));
		for(;i<=num2;i+=11)
		{
			//pi(i)
			k=find_diff(i);
			//pi(k)
			if(k==1)
				ans++;
			//ps("I was here not there")
		}
	}
	return ans;
}
	
	


int main()
{
	int t,i,j,k,ans,temp,len1,len2,num1,num2;
	char ch1[10],ch2[10];
	si(t)
	FOR(i,t)
	{
		si(num1)
		si(num2)
		ans=ra(num1,num2);
		pi(ans)

	}
}