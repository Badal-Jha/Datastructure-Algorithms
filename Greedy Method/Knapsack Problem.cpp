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

int gcd(int a,int b){
                 if(b==0)return a;
                 else return gcd(b,a%b);
}


int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,w;
    cin>>n>>w;
   double profit[n],weight[n];
    rep(i,n)cin>>profit[i];
    rep(i,n)cin>>weight[i];
    vector<pair<double,pair<double,double> >> v;
    rep(i,n){
    	v.push_back(make_pair(profit[i]/weight[i],make_pair(profit[i],weight[i])));
	}

	sort(v.rbegin(),v.rend());
	double ans=0,res=0;
	//logic of knapsack-> apply greedy method selection criteria is higher profit/weight value
	rep(i,n){
		if((w-v[i].second.second)>=0){
			ans+=1*v[i].second.first;
			w-=v[i].second.second;
			}
		else{
			ans+=(w/v[i].second.second)*v[i].second.first;
			w-=v[i].second.second;
		}
		if(w<0)break;
	}
	cout<<ans<<endl;
return 0;

}

