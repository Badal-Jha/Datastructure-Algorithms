//pair is a c++ stl used to store to element at a time.it is defined in <utility> header.
//pair is to combine to value which are different in type.
#include<iostream>
#include<utility>
using namespace std;
int main()
{
    pair<int,int>p1={2,4};//pair whoes both data is integer;
    pair<int,string>p2={2,"Badal"};
    pair<int,pair<int,string>>p3={2,{3,"badal"}};//pair also can consist pair inside it

    cout<<"first data: "<<p1.first<<" second data: "<<p1.second<<endl;
    cout<<"first data: "<<p2.first<<" second data: "<<p2.second<<endl;
    
    cout<<"first data: "<<p3.first<<" fist of second data: "<<p3.second.first<<" second of second data: "<<p3.second.second<<endl;
    

    return 0;
}
