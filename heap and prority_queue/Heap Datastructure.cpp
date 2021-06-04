#include<iostream>
#include<algorithm>
using namespace std;
void insert(int *heap,int n)
{
    int i=n;
    int temp=heap[n];
    while(i>1 && temp>heap[i/2]){
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=temp;
}

//delete element from heap
//NOte:we can only delete root of a heap
int deleteHeap(int *heap,int n)
{
	int i,j,delVal,temp;
	delVal=heap[1];
	int x=heap[n];
	heap[1]=heap[n];
	heap[n]=delVal;
	i=1;
	j=2*i;
	while(j<n-1){
		if(heap[j+1]>heap[j])
		j=j+1;
		if(heap[i]<heap[j])
		{
	     	temp=heap[i];
	     	heap[i]=heap[j];
	     	heap[j]=temp;
			i=j;
			j=2*i;
		}
		else break;
	}
	return delVal;
}

int main()
{
  int n;
   n=8;
   //we have to make is index start from 1 so set 0th index equal to 0
  int heap[]={0,10,20,30,25,5,40,35};
  
  for(int i=2;i<n;i++)
  insert(heap,i);

//  for(int i=1;i<n;i++)cout<<heap[i]<<" ";

//  
// printf("deleted element is: %d\n",deleteHeap(heap,7));  
//  printf("deleted element is: %d\n",deleteHeap(heap,6)); 
//  cout<<"\n"; 


//      heap sort    //
  
  //delete one by one
  printf("____Heap sorting____\n\n\n");
  
  for(int i=7;i>=1;i--)
  {
  	 deleteHeap(heap,i);
  }
 
  for(int i=1;i<=7;i++)
  cout<<heap[i]<<" ";
  
  return 0;
}
