#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;

#define FOR(i,n)    for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);



int find1(int temp,int *a,int size)
{
    int start,end,pos1,pos2,ans,mid;
	start=0;
	end=size-1;
	mid=(start+end)/2;
	//This loop is for finding pos1 such that a[pos1]>temp or pos1=size
	while(start<=end)
	{
		ps("Stuck here")
		if(a[mid]<=temp)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
		mid=(start+end)/2;
	}
	if(a[mid]<=temp)
	{
		pos1=mid+1;
	}
	else
		pos1=mid;


	start=0;
	end=size-1;
	mid=(start+end)/2;
	//This loop is for finding pos1 such that a[pos1]>temp or pos1=size
	while(start<=end)
	{
		ps("Stuck there")
		if(a[mid]>=temp)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
		mid=(start+end)/2;
	}
	if(a[mid]>=temp)
	{
		pos2=mid-1;
	}
	else
		pos2=mid;

	ans=pos1-(pos2+1);
	return ans;


}

int find(int temp,int *a,int size)
{
	int start,end,mid,i,j,flag=0;
	start=0;
	end=size-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(a[mid]==temp)
		{
			flag=1;
			break;
		}
		else if(a[mid]>temp)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	if(flag==0)
		return 0;
	else
	{
		for(i=mid-1;i>=0;i--)
		{
			if(a[i]!=temp)
				break;
			flag++;
		}
		for(i=mid+1;i<size;i++)
		{
			if(a[i]!=temp)
				break;
			flag++;
		}
		return flag;

	}
}

int main()
{
    int a[1000];
    int n,i,j,k;
    si(n);
    FOR(i,n)
    {
        si(a[i]);
    }
    si(i)
    j=find(i,a,n);
    k=find1(i,a,n);
    if(j==k)
    	ps("Mission accomplished")
    else
    	ps("Abort")

    return 0;
}