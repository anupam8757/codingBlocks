/*
Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

Input Format
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints
1<= n <= 1000
1<= sum <= 10^5
1<= Ai <=10^4

Output Format
Yes, if sum exist No, it sum does not exist

Sample Input
5 10
1 2 3 4 5
Sample Output
Yes*/
#include<iostream>
using namespace std;

#include <stdio.h> 
#include <stdbool.h> 
  
bool subsetSum(int arr[], int n, int sum) 
{ 
    // The value of subset[i%2][j] will be true  
    // if there exists a subset of sum j in  
    // arr[0, 1, ...., i-1] 
    bool subset[2][sum + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
  
            // A subset with sum 0 is always possible  
            if (j == 0) 
                subset[i % 2][j] = true;  
  
            // If there exists no element no sum  
            // is possible  
            else if (i == 0) 
                subset[i % 2][j] = false;  
            else if (arr[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2] 
             [j - arr[i - 1]] || subset[(i + 1) % 2][j]; 
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
        } 
    } 
  
    return subset[n % 2][sum]; 
} 
int main() {
	int n,target;
	cin>>n>>target;
	int arr[100000];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	bool result=subsetsum(arr,n,target);
	if(result)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0;
}