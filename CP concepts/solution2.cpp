#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<utility>

using namespace std;
typedef long long ll;
typedef long double ld;

#define endl "\n"

//vectors
#define vi vector<int>
#define vll vector<ll>
#define viip vector<pair<int, int>>
#define vllp vector<pair<ll, ll>>

//loops
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repp(i, a, b) for (ll i = (a); i < (b); ++i)
#define repr(i, a, b) for (ll i = (a); i >= (b); --i)
//pairs
#define pi pair<int, int>
#define pll pair<ll, ll>
#define  maxN 1000005
 int p[maxN]={0};
 vector<ll>v;
void sieve_Prime()
{  
	for(int i=3;i<=maxN;i+=2)
	{
	
	p[i]=1;}
	p[0]=p[1]=0;
	p[2]=1;
	for(int i=3;i<=sqrt(maxN);i+=2)
	{   
		if(p[i]==1)
		{
			for(int j=i*i;j<=maxN;j+=i)
		    {	p[j]=0;
	         
			   } 
		}
	}
	rep(i,maxN)if(p[i])v.push_back(i);
}

int gcd(ll a,ll b){
                 if(b==0)return a;
                 else return gcd(b,a%b);
}


int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    sieve_Prime();
    while(t--){
    	ll n;
    	cin>>n;
    	ll arr[n];
    	rep(i,n){
    		cin>>arr[i];
		}
		
		ll k=0,x=0;
		vector<ll>v2;
		rep(i,n)
		{
			if(i!=n-1 && gcd(arr[i],arr[i+1])!=1){
				arr[i]=min(arr[i],arr[i+1]);
				while(arr[i+1]%v[x]==0 || v[x]<=arr[i] )x++;
				arr[i+1]=v[x];
				v2.push_back(i+1);
				v2.push_back(i+2);
				x++;
				k++;
			
			}
		}
	    cout<<k<<endl;
	    
	    rep(i,n)cout<<arr[i]<<" ";
	    cout<<endl;
	    if(k!=0){
	    	for(auto x:v2)cout<<x<<" ";
		}
		cout<<endl;
	}
return 0;

}

