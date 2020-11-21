#include<stdio.h>
int main()
{   int ch,a,b;
	
	do{
       
	
	 printf("\n1.AND, 2.OR, 3.NOT:\n");
	printf("Enter your choice: \n");
	scanf("%d",&ch);
	printf("Enter A:\n");
	scanf("%d",&a);
	printf("Enter B:\n");
	scanf("%d",&b);
	switch(ch)
	{
		case 1:  if(a==1 && b==1)
	        	printf ("A*B:1");
	        	else
	        	printf("A*B: 0");
	        	
	        	break;
		case 2: 	if(a==0 && b==0)
	            printf("A+B : 0\n");
               else
               printf("A+B :1\n");
               break;
	    case 3: 
		
		         if(a==1)
	             printf("A : 0\n");
	            else
	             printf("A: 1\n");
	             if(b==1)
	              printf("B : 0\n");
	             else
	               printf("B : 1\n");
	               break;
	    default: printf("Enter correct choice\n");
	}}
	while(ch==1 || ch==2 || ch==3);
	
	return 0;
}
