/*
Reverse a Stack using Recursion. Do not use any extra stack.

Input Format
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

Constraints
1 <= N <= 10^4

Output Format
Output the values of the reversed stack with each value in one line each.

Sample Input
3
3
2
1
Sample Output
3
2
1
Explanation
Original Stack = [ 3 , 2 , 1 ] <-TOP
Reverse Stack = [ 1 , 2 , 3 ] <-TOP */

#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int> &s,int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	insertatbottom(s,x);
	s.push(y);
}
void reversestack(stack<int> &s)
{
	if(s.empty())
	return;
	int x=s.top();
	s.pop();
	reversestack(s);
	insertatbottom(s,x);
}
int main() {
	int n,temp;
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		s.push(temp);
	}
	reversestack(s);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}