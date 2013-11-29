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

#define FORi(i,a,n)	for(i=a;i<n;i++)

class travel
{
public:
	long long city_num;
	long long dist;
	void initialize(long long city,long long distance)
	{
		city_num=city;
		dist=distance;
	}
};

bool operator< (const travel a,const travel b)
{
	if(a.dist!=b.dist)
		return (a.dist>b.dist);
	else
		return (a.city_num>b.city_num);
}

/*bool greater(const travel a,const travel b)
{
	if(a.dist!=b.dist)
		return (a.dist<b.dist);
	else
		return (a.city_num<b.city_num);
}*/

int main()
{
	priority_queue <travel> b;

	travel temp1;
	int i,j,k;
	temp1.initialize(2,3);
//	priority_queue <travel> b;
	b.push(temp1);
	temp1.initialize(1,4);
	b.push(temp1);
	temp1.initialize(3,1);
	b.push(temp1);
	//temp1=b.pop();
	while (!b.empty())
    {
    	cout << " " << (b.top()).dist;
    	b.pop();
    }
    cout << endl;
  	return 0;
}