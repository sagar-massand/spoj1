#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sc(n)		scanf(" %c",&n);

#define FORi(i,a,n)	for(i=a;i<n;i++)

/*
H(i+1)=aHi - bFi
Fi+1=cFi + dHi

if(b==0)
Hi=a^iH0
Fi+1=cFi + d (a^i)H0
let 
Fn=Z a^n;
Z(a-c)a^n= dH0(a^n)
Z=d

*/
/*
harei = C1g1^i +C2g2^i
foxi= ((a-g1)C1/b)g1^i + ((a-g2)C2/b)g2^i
Also,g=((a+c)+-sqrt((a+c)^2-4(ac+bd)))/2 (If b!=0)

Case 1:Ecological balance will develop.

i.e.
if b!=0
{
	max(g1,g2)<1
}

Case 2:Hares will die out while foxes will overgrow.

if(b!=0)
{
	if(g1>g2)
		c1<0
		d1>0
	else
		c2<0
		d2>0
	min(g1,g2)>1
}

Case 3:Hares will overgrow while foxes will die out.
if(b!=0)
{
	if(g1>g2)
		c1>0;
		d1<0
	else
		c2>0;
		d2<0
	min(g1,g2)>1
}

Case 4:Both hares and foxes will die out
if(b!=0)
{
	if(g1>g2)
		c1<0
		d1<0
	else
		c2<0
		d2<0
	min(g1,g2)>1
}

Case 5:Both hares and foxes will overgrow.
if(b!=0)
{
	if(g1>g2)
		c1<0
		d1<0
	else
		c2<0
		d2<0
	min(g1,g2)>1
}
*/

int main()
{
	double a,b,c,d,x,y,z,fox0,hare0;
	long long t,i,j,k;


}