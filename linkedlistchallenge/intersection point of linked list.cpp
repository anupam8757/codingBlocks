/*
Check if a linked list is a palindrome.( Boolean return type )

Input Format
Add N space separated elements in the list

Constraints
None

Output Format
Boolean answer( true or false)

Sample Input
5
1 2 3 6 8
Sample Output
False*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n1;
	cin>>n1;
	list<int> l1;
	for(int i=0;i<n1;i++)
	{
		int num;
		cin>>num;
		l1.push_back(num);
	}
	auto it=l1.begin();
	auto it1=l1.end();
	int n=0;
	it1--;
	if(n1%2==1)
	n1=n1/2+1;
	else
	n1=n1/2;
	for(int i=0;i<n1;i++)
	{
		if((*it)==(*it1))
		{
		n++;
		}
		else{
			cout<<"false";
			break;
		}
		it++;
		it1--;
	}

	
	if(n==n1)
	cout<<"true";
	
	return 0;
}