//BADAL KUMAR JHA
//ROLL NO.:1901610100046

#include<stdio.h>
#include<stdlib.h>
struct Node{
	 int data;
	 struct Node *next;
};

struct Node *next=NULL;

struct Node *insertBegin(struct Node *head,int x)
{
struct Node *temp=malloc(sizeof(struct Node));
temp->data=x;
temp->next=head;
return temp;
}

struct Node *insertEnd(struct Node *head,int x)
{ 
   struct Node *temp=malloc(sizeof(struct Node));
   temp->data=x;
   if(head==NULL)
   {temp->next=NULL;
   return temp;
   }
   struct Node *curr=head;
   while(curr->next!=NULL)
   {
   	curr=curr->next;
   }
   curr->next=temp;
   temp->next=NULL;
   return head;
	
	
}

struct Node *delBegin(struct Node *head)
{
  if(head==NULL)
  {
  	printf("list is empty ");
  	return NULL;
	  }	
  else
  {
  	struct Node *temp=head->next;
  
    free(head);
    return temp;
	}  
	
	
}

struct Node *delEnd(struct Node *head)
{
    if(head==NULL){
    	printf("linked list is Empty:");
    	return NULL;
	}
	if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	struct Node *curr=head;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
		}	
	free(curr->next);
	curr->next=NULL;
	return head;	
}

void print(struct Node *head)
{   if(head==NULL)
    {
	   printf("list is empty :\n");
	   return;
    }
	struct Node *curr=head;
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
}
int main()
{
   struct Node *head=NULL;
    
  printf("enter 1 to insert at begin:\n");
  printf("enter 2 to insert at end:\n");
  printf("enter 4 to delete fron front:\n");
  printf("enter 5 to delete from end\n");
  printf("enter 3 to print:\n");
  printf("enter 0 to end\n");
    while(1)
     {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        if(n==1)
        {  printf("enter data to insert at begin: ");
        int x;
        scanf("%d",&x);
        	head=insertBegin(head,x);
		}
		if(n==2)
		{printf("enter data to insert at end: ");
		int x;
		scanf("%d",&x);
		head=insertEnd(head,x);
			
		}
		if(n==3)
		{  printf("linked list is: ");
			print(head);
		}
		if(n==4){printf("deleting from front\n");
		head=delBegin(head);}
		if(n==5){
			printf("deleting from end\n");
			head=delEnd(head);
		}
       
	 }
 
   
   
	return 0;
}


