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

#define si(n)		scanf("%d",&n);

#define sl(n)		scanf("%lld",&n);

#define ss(n)		scanf("%s",n);

#define sf(n)		scanf("%lf",&n);

#define sc(n)		scanf(" %c",&n);

#define mod 1000000007

//#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

int find_bits(int max)
{
	int i=0,j,k;
	while(max!=0)
	{
		i++;
		max/=2;
	}
	return i;
}

int find_power(int max)
{
	int i=1,j,k;
	max--;
	while(max!=0)
	{
		i*=2;
		max/=2;
	}
	return i;
}

void initialize(std::vector<int> *v,int num_bits,int power,std::vector<int> num,int n,std::vector<int> *v1)
{
	int i,j,k,zero=power-1,temp;
	FOR(i,num_bits)
	{
		FOR(j,power-1)
		{
			v[i].push_back(1);
			v1[i].push_back(1);
		}

		FORi(k,0,n)
		{
			temp=num[k]%2;
			v[i].push_back(temp);
			v1[i].push_back(temp);
			num[k]/=2;
		}
	}
}

void modify(std::vector<int> *q,int current_bit,int power,int n,int start,int end)
{
	int i,j,k,zero=power-1;

	if(start<end)
	{
		start+=zero;
		end+=zero;
		q[current_bit][start]=0;
		q[current_bit][end]=0;
		while(((start-1)/2)!=((end-1)/2))
		{
			if(start%2==1)
				q[current_bit][start+1]=0;
			if(end%2==0)
				q[current_bit][end-1]=0;
			start=((start-1)/2);
			end=((end-1)/2);
		}
	}
	else if(start==end)
	{
		start+=zero;
		q[current_bit][start]=0;
	}
	else
	{
		modify(q,current_bit,power,n,start,n-1);
		modify(q,current_bit,power,n,0,end);
	}
}
/*int check_bit(std::vector<int> *q,int num,int current_bit,int power)
{
	int i,j,k;
	while(num>0)
	{
		if(q[current_bit][num]==0)
			return 0;
		num=((num-1)/2);
	}
	if(q[current_bit][num]==0)
		return 0;
	return 1;
}*/
void print_num(std::vector<int> *q,int num_bits,int power,int n)
{
	int a,b,c,temp,num,flag;
	FORi(a,power-1,power+n-1)
	{
		temp=0;
		for(b=num_bits-1;b>=0;b--)
		{
			flag=1;
			temp*=2;
			num=a;
			while(num>0)
			{
				if(q[b][num]==0)
				{
					flag=0;
					break;
				}
				num=((num-1)/2);
			}
			if(q[b][num]==0)
				flag=0;

			temp+=flag;
		}
		if(a<(power+n-2))
		{
			printf("%d ",temp);
		}
		else
		{
			printf("%d\n",temp);
		}
		//pi(temp)
	}
}
void change(std::vector<int> *v,int num_bits,int power,std::vector<int> num,int n,int k,std::vector<int> *v1)
{
	int zero=power-1,temp,a,b,c,start,end;
	FOR(a,num_bits)
	{
		b=power-1;
		if(v[a][b]==0)
		{
			start=(b-(k+zero));
			end=(b+k-zero);
			start+=n;
			start%=n;
			end%=n;
			modify(v1,a,power,n,start,end);
		}
		b++;
		if(v[a][b]==0)
		{
			if(v[a][b-1]==0)
			{
				//start=(b-(k+zero));
				end=(b+k-zero);
				//start+=n;
				//start%=n;
				end%=n;
				//v1[a][start]=0;
				v1[a][end+zero]=0;
			}
			else
			{
				start=(b-(k+zero));
				end=(b+k-zero);
				start+=n;
				start%=n;
				end%=n;
				modify(v1,a,power,n,start,end);
			}
		}
		FORi(b,power,power+n-1)
		{
			if(v[a][b]==0)
			{
				start=(b-(k+zero));
				end=(b+k-zero);
				start+=n;
				start%=n;
				end%=n;
				if(v[a][b-1]==0)
				{
					v1[a][end+zero]=0;
				}
				else if(v[a][b-2]==0)
				{
					v1[a][end+zero-1]=0;
					v1[a][end+zero]=0;
				}
				else
				{
					modify(v1,a,power,n,start,end);
				}
				
			}
		}
	}
}
void printer(std::vector<int> *q,int max_bits,int power,int n)
{
	int a,b,c,i,j,k,temp=((power+n-2)/2);
	int temp1,zero=(power-1);

	FOR(i,max_bits)
	{
		FOR(j,temp)
		{
			if(q[i][j]==0)
			{
				q[i][2*j+1]=0;
				q[i][2*j+2]=0;
			}
			if(n%2==1)
			{
				if(q[i][temp]==0)
					q[i][2*temp+1]=0;
			}
			else
			{
				if(q[i][temp]==0)
				{
					q[i][2*temp+1]=0;
					q[i][2*temp+2]=0;
				}
			}
		}
	}
	FOR(a,n)
	{
		temp1=0;
		for(b=max_bits-1;b>=0;b--)
		{
			temp1*=2;
			temp1+=q[b][a+power-1];
		}
		printf("%d ",temp1);
	}
	printf("\n");
}
int main()
{
	int i,j,k,n,t;
	std::vector<int> v[32];
	std::vector<int> v1[32];
	std::vector<int> num;
	si(t)
	FOR(i,t)
	{
		int temp,temp1,power,max_bits,max;
		si(n)
		si(k)
		num.clear();
		si(temp)
		num.push_back(temp);
		max=temp;
		FORi(j,1,n)
		{
			si(temp)
			num.push_back(temp);
			if(max<temp)
				max=temp;
		}
		if(k>=n/2)
		{
			temp1=num[0];
			FORi(j,1,n)
			{
				temp1=(temp1&num[j]);
			}
			FOR(j,n-1)
			{
				printf("%d ",temp1);
			}
			printf("%d\n",temp1);
		}
		else
		{
			max_bits=find_bits(max);
			power=find_power(n);
			FOR(j,32)
			{
				v[j].clear();
				v1[j].clear();
			}
		//	pi(max_bits)
		//	pi(power)
		//	ps("B4 initialize")
			initialize(v,max_bits,power,num,n,v1);
		/*	FOR(j,max_bits)
			{
				cout <<  v[j].size() << endl;
				FOR(k,v[j].size())
				{
					pi(v[j][k])
				}
			}*/
		//	ps("B4 copy")
		//	copy(v,v1,max_bits,n,power);
		//	ps("B4 change")
			change(v,max_bits,power,num,n,k,v1);
			//ps("B4 print_num")
		//	print_num(v1,max_bits,power,n);
			printer(v1,max_bits,power,n);
		}
			
	}

}