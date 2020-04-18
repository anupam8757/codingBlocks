/*
Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	list<int> l1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		l1.push_back(num);
	}
	for(auto itr=l1.begin();itr!=l1.end();itr++)
	{
		if(*itr%2==1)
		cout<<(*itr)<<" ";
	}
	for(auto itr=l1.begin();itr!=l1.end();itr++)
	{
		if(*itr%2==0)
		cout<<(*itr)<<" ";
	}
	return 0;
}