//priority_queue of min_heap
//push and pop() take O(logn) time in priority_queue and top() and size() take O(1)
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> >pq;//this expression is for using min_heap in priority_queue
	
   	pq.push(10);
	pq.push(15);
	pq.push(5);
	
	cout<<pq.size()<<endl;
	
	cout<<pq.top()<<endl;
	while(pq.empty()!=true)
	{
		cout<<pq.top()<<" ";
		pq.pop();	
		}
	
}
