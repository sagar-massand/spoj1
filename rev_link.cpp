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

#define max 100000000

#define FORi(i,a,n)	for(i=a;i<n;i++)

struct node
{
	int value;
	struct node *next;
};
struct node * push(int val,struct node *temp)
{
	struct node *nim;
	if(temp==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->value=val;
		temp->next=NULL;
	//	head=temp;
	}
	else
	{
		nim=(struct node *)malloc(sizeof(struct node));
		nim->value=val;
		nim->next=NULL;
		temp->next=nim;
		temp=nim;
	}
	return temp;
}
struct node *reverse(struct node *head,struct node *nim)
{
	struct node *ans;
	if(nim==NULL)
		return head;
	else
	{
		struct node *temp,*t1;
		temp=nim->next;
		nim->next=head;
		ans=reverse(nim,temp);
	}
	return ans;
}
int main()
{
	struct node *temp,*head,*tail,*t1;
	int size=0,i,j,k;
	temp=NULL;
	head=NULL;
	FOR(i,5)
	{
		if(size==0)
		{
			head=push(i,temp);
			size++;
			temp=head;
		}
		else
		{
			temp=push(i,temp);
			size++;
			temp=head;
		}
			
	}
	if(head!=NULL)
	{
		t1=head->next;
		head->next=NULL;
		tail=reverse(head,t1);
	}
	pi(tail->value)
}