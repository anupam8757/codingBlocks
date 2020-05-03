/*
There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

Input Format
First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

Constraints
1<=N<=10^7
1<=k<=N
1 <= Ai <= 100000

Output Format
Space separated integers in a single line denoting strength of strongest fighters in the groups.

Sample Input
5
1 3 1 4 5
3
Sample Output
3 4 5
Explanation
First sub-group: 1 3 1 --> Max strength is 3
Second sub-group: 3 1 4 --> Max strength is 4
Third sub-group: 1 4 5 --> Max strength is 5*/


#include<iostream>
#include<deque>
using namespace std;
void findlargest(int *arr,int n,int k)
{
	//first process k element
	deque<int> q;
	int i=0;
	for(;i<k;i++)
	{
		while(!q.empty() && arr[i]>arr[q.back()])// add index to q which may be later  required
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	//process remaining n-k elemenet
	for(;i<n;i++)
	{
		cout<<arr[q.front()]<<" ";
		// remove index which are not coming in window
		while(!q.empty() && q.front()<=i-k)
		{
			q.pop_front();
		}
		while(!q.empty() && arr[i]>arr[q.back()])// add index to q which may be later  required
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	cout<<arr[q.front()];
}
int main() {
	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	int k;
	cin>>k;
	findlargest(arr,n,k);
	return 0;
}