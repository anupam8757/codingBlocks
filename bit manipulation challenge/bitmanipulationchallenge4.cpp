/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number*/
#include<iostream>
using namespace std;
int main() {
	int n,arr[10000];
	cin>>n;
	int res=0;
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	res=res^arr[i];
	}
	int temp=res;//to find first set bit
	int pos=0;
	while((temp&1)!=1)
	{
		
		pos++;
		temp=temp>>1;

	}
	int mask = 1<<pos;
	int x=0,y=0;// to store both unique number
	for(int i=0;i<n;i++)
	{
		if((arr[i] & mask)>0)
		{
			x=x^arr[i];// store 1st unique number
		}
	}
	y=res^x;//res contain both x and y hence x will cancel out from res y will left
	cout<<min(x,y)<<" "<<max(x,y);
	return 0;
}