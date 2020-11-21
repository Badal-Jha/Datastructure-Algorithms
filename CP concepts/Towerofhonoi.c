#include<stdio.h>
int main()
{
   int a[10] = {1,9,22,32,34,54,56,58,62,24};
   int low=0,mid=0,high=9,x;
   int flag=0;
  
    printf("\nsorted Array :\n");
    int i;
    for( i=0;i<10;i++)
        printf(" %d",a[i]);
        
    printf("\nEnter value to be searched :");
    scanf("%d",&x);
    printf("\n");
    while(low<=high)
    {
        mid = (low+high)/2;
        if(x==a[mid])
        {
            flag = 1; break;
        }
        if(x<a[mid])
            high = mid-1;
        else
            low = mid+1;     
    }
    if(flag==1)
     printf("\nElement %d is at %d position..",x,mid+1);
    else
     printf("Element is not found");
   
    return 0;
}


