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

int check(char c,char *nu,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(nu[i]==c)
            return 1;
    }
    return 0;
}

int complete(int *flag,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(!flag[i])
            return 0;
    }
    return 1;
}
int find(char c,char *nu,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(nu[i]==c)
            return i;
    }
}
void print(int *flag,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        cout<<flag[i]<<' ';
    }
    cout<<endl;
}
int main()
{
    char *a;
    char *s; 
    int *flag;
    char last;
    int n,i,j,k,len,min,current=-1,temp,start_min,end_min;
    cin>>n;
    a=(char *)malloc(n*sizeof(char));
    flag=(int *)malloc(n*sizeof(int));
    s=(char *)malloc(1000001*sizeof(char));
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        cin>>a[i];
    }
    
    cin>>s;
    char e,f,g;
    len=strlen(s);
    min=len;
    queue <int> num;
    queue <char> ch;
    for(i=0;i<len;i++)
    {
        if(check(s[i],a,n))
        {
            flag[find(s[i],a,n)]++;
        //    print(flag,n);            
            ch.push(s[i]);
            num.push(i);
            current=i;
            last=s[i];
        }
        while(complete(flag,n))
        {
        //    cout<<"Current is"<<current<<' '<<num.front()<<endl;
            temp=current-num.front();
            if(temp<min)
            {
                min=temp;
                start_min=num.front();
                end_min=current;
            //    cout<<"Start and end are "<<start_min<<' '<<end_min<<endl;
            }

            e=ch.front();
            flag[find(e,a,n)]--;
            num.pop();
            ch.pop();


        }
    }
    for(i=start_min;i<=end_min;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}