#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<time.h>
using namespace std;

#define FOR(i,n)	for(i=0;i<n;i++)

#define pi(n)		printf("%d\n",n);

#define pl(n)		printf("%lld\n",n);

#define ps(c)		printf("%s\n",c);

#define pf(n)		printf("%lf\n",n);

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

#define FORi(i,a,b)	for(i=a;i<b;i++)

void swap1(double *assess,long long a,long long b)
{
	double temp;
	temp=assess[a];
	assess[a]=assess[b];
	assess[b]=temp;
}

double find_marks(double *assess,double final,double attend)
{
	double assess_marks,final_marks,attend_marks,marks;
	if(assess[0]<assess[1])
	{
		swap1(assess,0,1);
	}
	if(assess[1]<assess[2])
	{
		swap1(assess,1,2);
	}
	assess_marks=(1.125*(assess[0]+assess[1]));
//	printf("Assess marks are %lf\n",assess_marks);
	final_marks=(0.5*final);
//	printf("Final marks are %lf\n",final_marks);
	if(attend<51)
		attend_marks=5;
	else if(attend<61)
		attend_marks=4;
	else if(attend<71)
		attend_marks=3;
	else if(attend<81)
		attend_marks=2;
	else if(attend<91)
		attend_marks=1;
	else
		attend_marks=0;
//	printf("Attend marks are %lf\n",attend_marks);
	marks=attend_marks+final_marks+assess_marks;
	return marks;
}
long long find_grade(double marks)
{
	if(marks>=91)
		return 10;
	else if(marks>=81)
		return 9;
	else if(marks>=71)
		return 8;
	else if(marks>=61)
		return 7;
	else if(marks>50.000001)
		return 6;
	else if((marks<=50.000001)&&(marks>=49.999999))
		return 5;
	else
		return 0;

}
double find_gpa(double *grade,double *credit)
{
	int i;
	long long total_credits=0;
	double gpa=0;
	FOR(i,6)
	{
		gpa+=(credit[i]*grade[i]);
		total_credits+=credit[i];
	}
	gpa/=((double)total_credits);
	return gpa;
}
int main()
{
	double credit[6],assess[3],final,attend,grade[6];
	double marks,a,b,c,gpa;
	long long t,i,j,k,fail,temp;
	char ch;
	sl(t)
	FOR(i,t)
	{
		fail=0;
		FOR(j,6)
		{
			sf(credit[j])
		}
		FOR(j,6)
		{
			sc(ch)
			if((ch>='0')&&(ch<='9'))
			{
				ungetc(ch,stdin);
				sf(assess[0])
			}
			else
			{
				sc(ch)
				assess[0]=0;
			}
			sc(ch)
			if((ch>='0')&&(ch<='9'))
			{
				ungetc(ch,stdin);
				sf(assess[1])
			}
			else
			{
				sc(ch)
				assess[1]=0;
			}	
			//	assess[1]=0;
			sc(ch)
			if((ch>='0')&&(ch<='9'))
			{
				ungetc(ch,stdin);
				sf(assess[2])
			}
			else
			{
				sc(ch)
				assess[2]=0;
			}
			//	assess[2]=0;
			sf(final)
			sf(attend)
			marks=find_marks(assess,final,attend);
		//	pf(marks)
			temp=find_grade(marks);
		//	pl(temp)
			if(temp==0)
				fail=1;
			grade[j]=(double)temp;
		}
		if(fail==0)
			printf("PASSED, ");
		else
			printf("FAILED, ");
		gpa=find_gpa(grade,credit);
		printf("%.2lf\n",gpa);
	}
	return 0;
}