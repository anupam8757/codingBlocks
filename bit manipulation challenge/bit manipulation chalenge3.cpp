/*count number of 1s in binary representation of an integer

Input Format
Input N = Number of Test Cases, followed by N numbers

Constraints
Output Format
Number of Set Bits in each number each in a new line

Sample Input
3
5
4
15
Sample Output
2
1
4
Explanation
Convert Binary to Decimal first and then count number of 1's present in all digits. */
#include<iostream>
using namespace std;
int setbit(int n)
{
	int ans=0;
	while(n>0)
	{
		int last_bit=(n&1);
		if(last_bit)
		ans++;
		n=n>>1;
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;//in memory decimalis always represented in binary
     cout<<setbit(n)<<endl;
		t--;
	}
	return 0;
}