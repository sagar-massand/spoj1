#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("1000");
	int j=1000000,i;
	for(i=0;i<100000;i++)
	{
		printf("%d\n",j);
		j+=301;
	}
	printf("0\n");
	return 0;
}
	
