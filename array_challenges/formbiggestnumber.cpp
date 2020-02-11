/*
You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

Input Format
First line contains integer t which is number of test case.
For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

Constraints
1<=t<=100
1<=m<=100
1<=A[i]<=10^5

Output Format
Print the largest value.

Sample Input
1
4
54 546 548 60
Sample Output
6054854654
Explanation
Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated. */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool mycampare(string x,string y)
{
	string xy =x.append(y);
	string yx =y.append(x);
  return xy>yx; 
}

int main() {
	int t;
	cin>>t;
	while(t) //number of testcase
	{
		int n;
		cin>>n;
		int arr[1000];
		vector<string> a;
		for(int i=0;i<n;i++)
		{
		cin>>arr[i];
		
		a.push_back(to_string(arr[i]));// conversion of int to string
		}
		sort(a.begin(),a.end(),mycampare);
		for(int i=0;i<n;i++)
		cout<<a[i];
		cout<<endl;
		t--;

	}
	return 0;
}