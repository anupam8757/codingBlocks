/*
You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

Input Format
First line contains integer t as number of test cases.
Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers denoting the elements for the BST.

Constraints
1 < t < 100
1< n < 1000

Output Format
For each testcase , print the preorder traversal of the BST in a new line.

Sample Input
1
7
1 2 3 4 5 6 7
Sample Output
4 2 1 3 6 5 7
Explanation
The tree looks like

             4
          /      \
       2           6
    /     \      /    \
   1       3    5      7
We print the preorder of the final tree. */
#include<iostream>
using namespace std;
class Node
{
	public:int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
 Node *Build(int *arr,int s,int e)
	{
	int mid=(s+e)/2;
	if(s>e)
	return NULL;
	Node *root=new Node(arr[mid]);
	root->left=Build(arr,s,mid-1); // make lst
	root->right=Build(arr,mid+1,e);// make rst
	return root;
	}
	void preorder(Node *root)
	{
		if(root==NULL)
		return;
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
		return;
	}
int main() {
	int t;      // testcase
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[1000];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		Node *root=Build(arr,0,n-1);
		preorder(root);
	}
	return 0;
}