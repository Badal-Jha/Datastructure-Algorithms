#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
void sieve_prime(ll *arr)
{
    for(int i=3;i<=100;i+=2)
    arr[i]=1;
    arr[0]=arr[1]=0;
    arr[2]=1;
    for(ll i=3;i<=sqrt(100);i+=2)
    {
        if(arr[i]==1)
        {
            for(int j=2;i+j<=100;j++)
            arr[i*j]=0;
        }
    }
    
}
int main() {
	// your code goes here
     	ll n;
	    cin>>n;
	    vector<ll>v;
	    ll arr[1000000]={0};
	    sieve_prime(arr);
	    v.push_back(2);
	    for(int i=3;i<=1000000;i+=2)
	    {
	        if(arr[i]==1)
	        v.push_back(i);
	    }
	    for(int i=0;i<n;i++)
	    cout<<"data"<<v[i]<<" ";
	    
	    cout<<endl;
	
	return 0;
}

