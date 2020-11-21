#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
void sieve_Prime(int *p)
{   int n;
    cin>>n;
	for(int i=3;i<=n;i+=2)
	{
	
	p[i]=1;}
	p[0]=p[1]=0;
	p[2]=1;
	for(int i=3;i<=sqrt(n);i+=2)
	{   
		if(p[i]==1)
		{
			for(int j=i*i;j<=n;j+=i)
		    {	p[j]=0;
	         
			   } 
		}
	}
}
int main()
{  
  int p[100005]={0};
  sieve_Prime(p);
   	 for(int i=3;i<1000;i+=2)
    {  if(p[i]==1)
        cout<<i<<" ";
    }

    return 0;
}
