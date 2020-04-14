/*
Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

Input Format
First Line contains T the number of test cases.
For each test case :
Line 1 : N1 the size of list 1
Line 2 : N1 elements for list 1
Line 3 : N2 the size of list 2
Line 4 : N2 elements for list 2

Constraints
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format
For each testcase , print the node data of merged linked list.

Sample Input
1
4
1 3 5 7
3
2 4 6
Sample Output
1 2 3 4 5 6 7 
Explanation
The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .*/

#include<iostream>
using namespace std;
class Node{
public:int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
void insertattail(Node *&head,int d)
{
	if(head==NULL)
	{
		head=new Node(d);
		return;
	}
	Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	Node *n=new Node(d);
	temp->next=n;
	n->next=NULL;
	return;

}
void insertlist(Node *&head,int k)
{
	int num;
	while(k--)
	{
		cin>>num;
		insertattail(head,num);
	}
}
Node *mergetwolinkedlist(Node *a,Node *b)
{
	if(a==NULL)//base case
	return b;
	else if(b==NULL)
	return a;
	Node *c;
	if(a->data<b->data)
	{
		c=a;
		c->next=(mergetwolinkedlist(a->next,b));
	}
	else{
		c=b;
		c->next=(mergetwolinkedlist(a,b->next));
	}
	return c;
}
int main() {
	int t;//testcase
	cin>>t;
	while(t--)
	{
		int n1;
		cin>>n1;
		Node *head1=NULL;
		insertlist(head1,n1);
		int n2;
		cin>>n2;
		Node *head2=NULL;
		insertlist(head2,n2);
		Node *head3=mergetwolinkedlist(head1,head2);
		while(head3!=NULL)
		{
			cout<<head3->data<<" ";
			head3=head3->next;
		}
	}
	return 0;
}