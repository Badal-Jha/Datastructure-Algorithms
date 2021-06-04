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
#define N 10000
int arr[N][N],I[N][N];
int gcd(int a,int b){
                 if(b==0)return a;
                 else return gcd(b,a%b);
}
void mul(int A[][N],int B[][N],int dim)
{   int res[dim][dim];
	rep(i,dim)
	{
		rep(j,dim)
		{  res[i][j]=0;
		   rep(k,dim)
		   res[i][j]+=A[i][k]*B[k][j];
		   	
		   
			
		}
	}
	rep(i,dim)rep(j,dim)A[i][j]=res[i][j];
}
void power(int A[][N],int dim , int n)
{
	rep(i,dim)rep(j,dim){
		if(i==j)I[i][j]=1;
		else I[i][j]=0;
	}
//	rep(i,n)
//	mul(I,A,dim);
//for O(m^3*logn)
while(n){
	if(n%2!=0)
	{
		mul(I,A,dim);
		n--;
	
	}
	else{
		mul(A,A,dim);
		n=n/2;
	}
}
   
	rep(i,dim)rep(j,dim)A[i][j]=I[i][j];
}

void printMat(int A[][N] , int dim){
	
	rep(i,dim)
	{
	rep(j,dim)
	cout<<A[i][j]<<" ";
	cout<<endl;}
	
}

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t,n,dim;
    cin>>t;
    while(t--)
    {
    	cin>>dim>>n;
    	rep(i,dim)rep(j,dim)cin>>arr[i][j];
    	power(arr,dim,n);
    	printMat(arr,dim);
	}
return 0;

}

