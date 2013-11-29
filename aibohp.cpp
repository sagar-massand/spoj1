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

int check_double(int mid2,char *ch,int min_add,int len)
{
	int i,j,k,temp;
	temp=len-1;
	if(ch[mid2]!=ch[mid2-1])
		return min_add;
	i=mid2+1;
	j=temp-i;
	while((i<len)&&(j>=0))
	{
		if(ch[i]==ch[j])
		{
			i++;
			j--;
		}
		else if(ch[i]==)
	}
}

int main()
{
	char ch[6102];
	int t,i,j,k,len,min_add,temp_add,len,a,b,c,flag1,flag2,d,e;
	si(t)
	FOR(i,t)
	{
		ss(ch)
		len=strlen(ch);
		min_add=len;
		flag1=0;
		flag2=0;
		
		if(len>1)
		{
			j=len/2;
			k=len-(j+1);

			
			a=0;
			while(1)
			{
				temp_add=0;
				b=j;
				c=j-1;
				d=j;
				e=j-1;
				if(a%2==0)
				{
					//Double center,starting with len/2 as d last one, den len/2-1
					//Go on till 1 or len-1.
					//2 checks in 1 if statement, den we move 1 step forward
					
					if((b==len)||(b==0))
					{
						flag1=1;
						break;
					}
					else
					{
						min_add=check_double(b,ch,min_add,len);
						min_add=check_double(c,ch,min_add,len);
						b++;
						c--;
					}
					a++;
				}
				else
				{
					//Single center, 2 checks again, with len/2, den len/2 -1
					//Go on till 0 and len-1.
					//2 checks in 1 if statement, den we move 1 step forward
					if((b==len)||(b<0))
					{
						flag2=1;
						break;
					}
					else
					{
						min_add=check_single(d,ch,min_add,len);
						min_add=check_single(e,ch,min_add,len);
						d++;
						e--;
					}
					a++;
				}
			}
			if(flag2==0)
			{
				while(1)
				{
					if((b==len)||(b<0))
					{
						flag2=1;
						break;
					}
					else
					{
						min_add=check_single(d,ch,min_add);
						min_add=check_single(e,ch,min_add);
						d++;
						e--;
					}
					//a++;
				}

			}
			if(flag1==0)
			{
				while(1)
				{
					if((b==len)||(b==0))
					{
						flag1=1;
						break;
					}
					else
					{
						min_add=check_double(b,ch,min_add);
						min_add=check_double(c,ch,min_add);
						b++;
						c--;
					}
				}
			}
			
			pl(min_add)
		}
		else
		{
			ps("0")
		}

	}
}