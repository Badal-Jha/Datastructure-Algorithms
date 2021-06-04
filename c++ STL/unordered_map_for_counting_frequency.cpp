//unordered_map uses hashing internally
//unordered_map used for count frequency of string
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
#include<map>
#include<unordered_map>
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
#define maxN 100005
#define modu 1000000007
int gcd(int a,int b){
                 if(b==0)return a;
                 else return gcd(b,a%b);
}
bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
 
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);
 int t;
 cin>>t;
  unordered_map<string,int>um;
 while(t--){
       
      string s;
      cin>>s;
      um[s]++;
       
      
	  	cout<<s<<um[s]<<endl;
	  
 
  }

 
return 0;
 
}
