// finding square root using binary search
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,precision;
    cout<<"Enter number and presion\n";
    cin>>num>>precision;
    float ans,inc=0.1;
    int mid=0,s=0,en=num,i;
    while(s<=en)
    {
        mid=(s+en)/2;
        if(mid*mid==num)
        {
        ans=mid;
        break;
        }
        else if(mid*mid>num)
            en=mid-1;
        else if(mid*mid<num)
        {
            ans=mid;
            s=mid+1;
        }
      //   en=mid-1;
    }
        for(i=0;i<precision;i++)
        {
            while(ans*ans<=num)
            {
                ans=ans+inc;
            }
            ans=ans-inc;
            inc=inc/10;

        }
    cout << "Hello world!" << endl;
    cout<<fixed<<setprecision(3)<<ans;
 return 0;
}
