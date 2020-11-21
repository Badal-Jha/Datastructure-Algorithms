#include<stdio.h>
#define Max_size 100
int A[Max_size];
int top=-1;
void push(int x)
{
	if(top==Max_size-1){
		printf("Stck overflow ");
		return;
	}
	top+=1;
	A[top]=x;
}
void pop()
{
	if(top==-1)
	{
		printf("Error:empty");
		return;
	}
	top--;
}
int Top()
{
  return A[top];
}
void print()
{
	int i;
	printf("data in stack are: ");
	for(i=0;i<=top;i++)
	printf("%d ",A[i]);
	printf("\n");
}
int main()
{   int n;
     	printf("enter 1 if you want to enter:\n");
		printf("enter 2 to pop:\n");
		printf("enter 3 to get topmost element\n");
		printf("enter 4 to print\n");
		printf("enter 0 to end\n");
	while(1)
	{   scanf("%d",&n);
	    if(n==0)break;
		if(n==1)
		{   int x;
			printf("enter data to push ");
			scanf("%d",&x);
			push(x);
		}
		if(n==2)
		{printf("Pop out...\n");
		}
		if(n==3)printf("value at top: %d",Top());
		if(n==4)print();
		
	}
	return 0;
}
