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
	long long t,i,j,k,n,a,c,flag,start,end,b,h,w,d,area=0,volume,calc_vol,new_vol;
	pos *an;
	double ans;
	sl(t);
	FOR(i,t)
	{

		area=0;
		flag=0;
		sl(n);
		an=(pos *)malloc(2*n*sizeof(pos));
		/*FOR(j,2*n)
		{
			an[j].initialize(0,0);
		}*/
		FOR(j,n)
		{
			sl(b);
			sl(h);
			sl(w);
			sl(d);
			an[2*j].initialize(b,w*d);
			an[2*j+1].initialize(b+h,-(w*d));
		}
	/*	FOR(j,2*n)
		{
			printf("The reference and area for index %lld is %lld and %lld respectively\n",j,an[j].ref,an[j].area);
			
		}
		ps("\n\n")*/
		sort(an,an+2*n,compare);
		sl(volume);
	/*	FOR(j,2*n)
		{
			printf("The reference and area for index %lld is %lld and %lld respectively\n",j,an[j].ref,an[j].area);
			
		}
	*/
		area=an[0].area;
		calc_vol=(an[1].ref-an[0].ref)*area;
		for(j=1;j<2*n;j++)
		{
			if(calc_vol>volume)
			{
				flag=1;
				break;
			}
			else if(calc_vol==volume)
			{
				ans=an[j].ref;
				flag=2;
				break;
			}

			area+=(an[j].area);
			calc_vol+=(an[j+1].ref-an[j].ref)*area;
		}
		if(flag==0)
		{
			ps("OVERFLOW")
		}
		else if(flag==2)
		{
			printf("%.2lf\n",ans);
		}
		else
		{
			new_vol=(calc_vol-(an[j].ref-an[j-1].ref)*area);
			ans=(an[j-1].ref+(double)((double)(volume-new_vol)/(double)area));
			printf("%.2lf\n",ans);
		}

		
	}
	return 0;
}