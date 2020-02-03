/*You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

Input Format
The first line contains N, which is the size of the array. The following N lines contain either 0, or 1, or 2.

Constraints
Each input element x, such that x ∈ { 0, 1, 2 }.

Output Format
Output the sorted array with each element separated by a newline.

Sample Input
5
0
1
2
1
2
Sample Output
0
1
1
2
2 */
#include<iostream>
using namespace std; 
int main() {
	int siz;
	cin>>siz;
	int arr[siz];
	for(int i=0;i<siz;i++)
	cin>>arr[i];
	int mid=0,high=siz-1,low=0;
	arr[mid]=arr[0],arr[low]=arr[0],arr[high]=arr[siz-1];
	while(mid<=high)
	{
		if(arr[mid]==0)
		{
			swap(arr[mid],arr[low]);
			mid++,low++;
		}
		else if(arr[mid]==1)
		mid++;
		else
		{
			swap(arr[mid],arr[high]);
			high--;
		}
	}
	for(int i=0;i<siz;i++)
	cout<<arr[i]<<endl;
	return 0;
}