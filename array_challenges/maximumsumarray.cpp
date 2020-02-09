#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[1000],currentsum=0,maximumsum=0;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currentsum=0;
            for(int k=i;k<=j;k++)
            {
            currentsum=currentsum+arr[k];
            }
            if(currentsum>maximumsum)
            maximumsum=currentsum;
        }
      
    }
  
    cout<<"maximum sum="<<maximumsum;
}
