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

int main()
{
	int a,b,c,t,i,j,k,fake,temp,temp2;
	si(t)
	char ch;
	FOR(i,t)
	{
		scanf(" %c",&ch);
		//printf("ch is %c\n",ch);
		if(ch!='x')
		{
			ungetc(ch,stdin);
			scanf("%d*x*x",&a);
			//printf("a is %d\n",a);
		}
		else
		{
			a=1;
			scanf(" %c",&ch);//For  *
			scanf(" %c",&ch);//For  x
			//printf("a is %d\n",a);
		}
		scanf(" %c",&ch);
		if(ch=='=')
		{
			ps("Equal roots.")
			scanf("%d",&temp);
			continue;
		}
		else 
		{
			if(ch=='-')
			{
				temp2=-1;
			}
			else
			{
				temp2=1;
			}
			scanf(" %c",&ch);
			if(ch!='x')
			{
				ungetc(ch,stdin);
				scanf("%d",&temp);
				scanf(" %c",&ch);
				if(ch=='*')
				{
					b=temp;
					b*=temp2;
					scanf(" %c",&ch);//For x scanning
					scanf(" %c",&ch);//for + or =
					if(ch=='=')
					{
						c=0;
						scanf("%d",&fake);
						
					}
					else
					{
						if(ch=='+')
							temp2=1;
						else
							temp2=-1;
						scanf("%d",&c);
						c*=temp2;
						scanf(" %c",&ch);
						scanf("%d",&fake);
					}
				}
				else
				{
					b=0;
					c=temp;
					c*=temp2;
					scanf("%d",&fake);
				}
			}
			else
			{
				b=1;
				scanf(" %c",&ch);
				if(ch=='+')
				{
					scanf("%d",&c);
					scanf(" %c",&ch);
					scanf("%d",&fake);
				}
				else if(ch=='-')
				{
					scanf("%d",&c);
					scanf(" %c",&ch);
					scanf("%d",&fake);
					c*=-1;
				}
				else
				{
					c=0;
					scanf("%d",&fake);
				}

			}
		}
		temp=(b*b-4*a*c);
		if(temp>0)
			ps("Distinct real roots.")
		else if(temp==0)
			ps("Equal roots.")	
		else
			ps("Imaginary roots.")		
			
		
	}
	return 0;
}