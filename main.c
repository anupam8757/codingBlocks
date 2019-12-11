#include <stdio.h>
#include <stdlib.h>
int a[]={1,2,3,4,5,6};
int n;
void bs(int k);
int main ()
{
    int k;
    n=6;
    k=4;
    bs(k);
    return 0;
}
void bs(int k)
{
    int i=0;
    int j=n-1;
    int mid;
    while(i<=j)
    {
        mid=i+j/2;
        if(a[mid]==k)
    {
        printf("Element found");
        return;
    }
    else if(k>a[mid])
        i=mid+1;
    else
     j=mid-1;
}
    printf("Element not found");
}
