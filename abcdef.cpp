#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

bool compare(int a, int b)
{
	return a<b;
}

int find1(int temp,int *a,int size)
{
    int start,end,pos1,pos2,ans,mid;
	start=0;
	end=size-1;
	mid=(start+end)/2;
	//This loop is for finding pos1 such that a[pos1]>temp or pos1=size
	while(start<=end)
	{
	//	ps("Stuck here")
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
	//	ps("Stuck there")
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
	int t,i,j,k,n,x,y,z,size,ans,temp;
	int a[100],b[1000000];
	int val;

		ans=0;
		si(n)
		FOR(j,n)
		{
			si(a[j])
		}
		j=0;
		FOR(x,n)
		{
			if(a[x]!=0)
			{
				FOR(y,n)
				{
					FOR(z,n)
					{
							b[j]=a[x]*(a[y]+a[z]);
							j++;

					}
				}
			}
		}
		size=j;
/*		FOR(j,size)
			pl(b[j]);
		ps("\n\n")
		sort(b,b+size,compare);
		FOR(j,size)
			pl(b[j]);
*/
		sort(b,b+size,compare);
		FOR(x,n)
		{
			FOR(y,n)
			{
				FOR(z,n)
				{
					temp=(a[x]*a[y])+a[z];
					val=find1(temp,b,size);
//					pl(temp)
					ans+=val;
				}
			}
		}
//		ps("\n\n")
		pi(ans);

		return 0;
}