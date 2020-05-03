/*
Implement a Queue using two stacks Make it Dequeue efficient.

Input Format
Enter the size of the queue N add 0 - N-1 numbers in the queue

Constraints
Output Format
Display the numbers in the order they are dequeued and in a space separated manner

Sample Input
5
Sample Output
0 1 2 3 4 */
#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> s1,s2;
	int n,temp;
	cin>>n;//size of stack
	for(int i=0;i<n;i++)//insert element to stack
	{
	s1.push(i);
	}
	while(!s1.empty())
	{
		temp=s1.top();
		s2.push(temp);// insert all elemnet of stack from s1 to s2
		s1.pop();
	}
	while(!s2.empty())// deque efficient
	{
		cout<<s2.top()<<" ";
		s2.pop();
	}
	return 0;
}