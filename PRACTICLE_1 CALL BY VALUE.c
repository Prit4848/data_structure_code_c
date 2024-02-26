#include<stdio.h>
void swap(int a,int b)
{ int error;
error=a;
a=b;
b=error;
printf("the value of a=%d and b=%d\n",a,b);
}

int main()
{
	int X,Y;
	printf("enter the value of X AND Y =\n");
	scanf("%d %d",&X,&Y);
	 
	 swap(X,Y);
	 printf("the value of X=%d and Y=%d\n",X,Y);
	 
	 return 0;
}

