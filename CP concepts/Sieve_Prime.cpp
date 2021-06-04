#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
#define  maxN 1000005
 int p[maxN]={0};
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
}
int main()
{  
 
   sieve_Prime();
   	 for(int i=3;i<1000;i+=2)
    {  if(p[i]==1)
        cout<<i<<" ";
    }

    return 0;
}
