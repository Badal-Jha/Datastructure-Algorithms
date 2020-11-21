#include<stdio.h>
#include<stdlib.h>
struct Queue{
	  int *arr;
	  int size;
	  int front,rear;
};

void enqueue(struct Queue *q,int x)
{
  if((q->rear+1)%q->size==q->front)	
  {
  	printf("queue is full ");
  }
  else if(q->rear==-1)
  {
  	q->rear=q->front=0;
  }
else
{  q->rear=(q->rear+1)%q->size;
  
	
} q->arr[q->rear]=x;}


int dequeue(struct Queue *q)
{   int x=-1;
	if(q->front==q->rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->arr[q->front];
	}
	return x;
}
void display(struct Queue *q)
{
  int i=q->front;
  do{
  	printf("%d ",q->arr[i]);
  	i=(i+1)%q->size;
  }	
  while(i!=(q->rear+1)%q->size)	;
  printf("\n");
		
}
int main()
{
  struct Queue *q= malloc(sizeof(struct Queue));
  printf("enter size: ");
  scanf("%d",&q->size);
  q->arr=(int *)malloc(q->size*sizeof(struct Queue));
  q->front=q->rear=-1;
  int n=1;
  printf("enter 1 to enqueue : \n");
  printf("enter 2 to dequeue : \n");
  printf("enter 3 to display : \n");
  while(n!=0)
  { printf("enter your choice: ");
  	scanf("%d",&n);
  	if(n==1)
  	{   int x;
  		printf("enter data to enqueue: \n");
  		scanf("%d",&x);
  		enqueue(q,x);
  		
	  }
	  else if(n==2)
	  {
	  	printf("delete %d\n",dequeue(q));
	  }
	  else if(n==3)
	  {
	  	printf("queue is : ");
	  	display(q);
	  }
  }
  return 0;
	
}
