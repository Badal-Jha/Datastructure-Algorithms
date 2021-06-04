//priority_queue//
//priority_queue is a c++ stl uses concept of heap internally
//note:it work like stack in stl
#include<iostream>
#include<queue>
using namespace std;
int main()
{  
////
////	priority_queue<int>pq;//by default it is an max_heap
////	pq.push(10);
////	pq.push(15);
////	pq.push(5);
//	
//	cout<<pq.size()<<endl;
//	
//	cout<<pq.top()<<endl;
//	while(pq.empty()!=true)
//	{
//		cout<<pq.top()<<" ";
//		pq.pop();	
//		}

//we can also use array to make priority queue
int arr[]={10,15,5};
priority_queue<int>pq(arr,arr+3);//this is better approch

	cout<<pq.size()<<endl;
	
	cout<<pq.top()<<endl;
	while(pq.empty()!=true)
	{
		cout<<pq.top()<<" ";
		pq.pop();	
		}

		return 0;
		
	}
