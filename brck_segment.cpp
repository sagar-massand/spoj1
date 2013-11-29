#include<cstdio>
#define LL long long int
#define F(i,a,b) for(i=a;i<=b;i++)
#define s(n) scanf("%d",&n)
int no[80000],fl[80000];
void refresh(int x,int b,int e)
{
	if (b==e)
	{
		no[x] += fl[x];
		fl[x] = 0;
		return;
	}
	no[x] += fl[x];
	fl[2*x] += fl[x];
	fl[2*x+1] += fl[x];
	fl[x] = 0;
}
void update(int x,int b,int e,int i,int j,int v)
{
}