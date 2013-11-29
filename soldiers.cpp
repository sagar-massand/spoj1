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

void initialize(char *ch,char *ch2,int len,int *num1)
{
	int temp,j,size;
	for(j=len-1;j>=0;j--)
	{
		ch2[j]=ch[len-(j+1)];
	}
	size=(len-1)/4;
	for(j=0;j<size;j++)
	{
		//num1[j]=0;
		num1[j]=((ch2[4*j]-'0')+((ch2[4*j+1]-'0')*10)+((ch2[4*j+2]-'0')*100)+((ch2[4*j+3]-'0')*1000));
	}
	int fin=1;
	temp=j*4;
	num1[j]=0;
	while(temp<len)
	{
		num1[j]+=(fin*(ch2[temp]-'0'));
		temp++;
		fin*=10;
	}
}

int multiply(int *final,int *num1,int size1,int *num2,int size2)
{
	int i,j,k;
	for(i=0;i<(size1+size2+6);i++)
	{
		final[i]=0;
	}
	for(i=0;i<=size1;i++)
	{
		FOR(j,size2+1)
		{
			final[i+j]+=(num1[i]*num2[j]);
			final[i+j+1]+=(final[i+j]/10000);
			final[i+j]%=10000;
		}
	}
	k=size1+size2+1;
	while(final[k]!=0)
	{
		//eturn (size1+size2+1);
		final[k+1]+=(final[k]/10000);
		final[k]%=10000;
		k++;
	}
	//return (size1+size2);
	return (k-1);
}
int divide(int *final,int size)
{
	int i,j,k;
	for(i=size;i>0;i--)
	{
		final[i-1]+=((final[i]%2)*10000);
		final[i]/=2;
	}
	final[0]/=2;
	for(i=0;i<=size;i++)
	{
		final[i+1]+=(final[i]/10000);
		final[i]%=10000;
	}
	if(final[size]==0)
		return (size-1);
	else
		return size;

}
int compare(int *num1,int size1,int *num2,int size2)
{
	int i;
	if(size1>size2)
		return 1;
	else if(size2>size1)
		return 2;
	else
	{
		i=size1;
		//j=size2;
		while(i>=0)
		{
			if(num1[i]==num2[i])
				i--;
			else
			{
				if(num1[i]>num2[i])
					return 1;
				else
					return 2;
			}
		}
		return 1;
	}
}
void print(int *final,int size)
{
	int i;
	printf("%d",final[size]);
	for(i=size-1;i>=0;i--)
	{
	//	printf("%d",final[i]);
		if(final[i]<10)
			printf("000%d",final[i]);
		else if(final[i]<100)
			printf("00%d",final[i]);
		else if(final[i]<1000)
			printf("0%d",final[i]);
		else
			printf("%d",final[i]);
	}
	printf("\n");
}
int main()
{
	char ch[110],ch2[110];
	int num1[110],num2[110],final[110],final2[110],fum[110];
	int i,j,k,a,b,c,t,temp,flag;
	si(t)
	FOR(i,t)
	{
		int len1,size,len2,size1,size2,gem1,gem2;
		ss(ch)
		len1=strlen(ch);
		initialize(ch,ch2,len1,num1);
		size1=(len1-1)/4;
		//pi(size1)
		ss(ch)
		len2=strlen(ch);
		size2=(len2-1)/4;
		initialize(ch,ch2,len2,num2);
		if((num1[0]%2==0)&&(num2[0]%2==0))
		{
			size=multiply(final,num1,size1,num2,size2);
			size=divide(final,size);
			print(final,size);
		}
		else if((num1[0]%2==1)&&(num2[0]%2==0))
		{
			num1[0]+=1;
			size=multiply(final,num1,size1,num2,size2);
			size=divide(final,size);
			print(final,size);
		}
		else if((num1[0]%2==0)&&(num2[0]%2==1))
		{
			num2[0]+=1;
		//	print(num1,size1);
		//	print(num2,size2);
			size=multiply(final,num1,size1,num2,size2);
			size=divide(final,size);
			print(final,size);
		}
		else
		{
			num1[0]+=1;
			gem1=multiply(final,num1,size1,num2,size2);
			num1[0]-=1;
			num2[0]++;
			gem2=multiply(final2,num1,size1,num2,size2);
			flag=compare(final,gem1,final2,gem2);
			if(flag==1)
			{
				size=divide(final,gem1);
				print(final,size);
			}
			else
			{
				size=divide(final2,gem2);
				print(final2,size);
			}

		}
	}
}