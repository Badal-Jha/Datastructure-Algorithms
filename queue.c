//queue using array
//Badal kumar jha
#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size,front,rear;
    int *arr;

};

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("Queue overflow");
    else{
        q->rear++;
        q->arr[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    printf("Queueis empty");
    else
    {
        q->front++;
        x=q->arr[q->front];
    }
    return x;
}
void display(struct Queue q)
{
    int i;
    for( i=q.front+1;i<=q.rear;i++)
    printf("%d ",q.arr[i]);
    printf("\n");
}
int main()
{
    struct Queue q;
    printf("Enter size:");
    scanf("%d",&q.size);
    q.arr=malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    int n=1;
    printf("enter 1 to enqueue\n");
    printf("enter 2 to dequeue\n");
    printf("enter 3 to print\n");
 
    while(n!=0)
    {
    	scanf("%d",&n);
    	if(n==1)
    	{
    		printf("enter data to enqueue: ");
    		int x;
    		scanf("%d",&x);
    		enqueue(&q,x);
		}
		if(n==2)
		{
			printf("dequeue : %d\n",dequeue(&q));
		}
		if(n==3)
		{
			printf("\nqueue is: ");
			display(q);
		}
	}
 
    return 0;
}


