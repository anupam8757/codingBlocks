/*
You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
Note : In case of node with 2 children, consider its inorder successor as its replacement.

Input Format
First line contains integer t as number of test cases.
Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.

Constraints
1 < t < 100
1< n,m < 1000

Output Format
Print the preorder traversal of the final resultant tree.

Sample Input
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output
6 4 7 8 
Explanation
Initially the tree looks like

             5
          /      \
       3           7
    /     \      /    \
   2       4    6      8
After the deletion , the tree looks like

               6
            /     \
           4       7
                     \
                      8
We print the preorder of the final tree. */
#include<iostream>
using namespace std;
class Node
{
	public: int data;
			Node *left;
			Node *right;
			Node(int d)
			{
				data=d;
				left=NULL;
				right=NULL;
			}

};
Node *insertintoBST(Node *root,int data)
{
	if(root==NULL)
	return new Node(data);
	if(data<= root->data)                      // insert into lst
	root->left=insertintoBST(root->left,data);
	else
	root->right=insertintoBST(root->right,data); // insert into rst
	return root;
}
Node *Build(int *arr1, int n1)
{
		Node *root=NULL;
		for(int i=0;i<n1;i++)
		{
			root=insertintoBST(root,arr1[i]);
		}
		return root;
}
void preorder(Node *root)
	{
		if(root==NULL)
		return;
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
Node *deleteBST(Node *root,int data)
	{
		if(root==NULL)
		return NULL;
		else if(data<root->data)							// search for data in lst
		{
			root->left=deleteBST(root->left,data);
			return root;
		}
		else if(root->data==data)   // data found
		{
			// Now there are 3 cases 
			// 1 case if current node has only no children leaf node
			if(root->left==NULL && root->right==NULL)
			{
				delete root;
				return NULL;  // return null to parent
			}
			// 2 case if current node has only 1 children
			if(root->left!=NULL && root->right==NULL) //having only left child
			{
				Node *temp=root->left;
				delete root;
				return temp;
			}
			if(root->left==NULL && root->right!=NULL) // having only right child
			{
				Node *temp=root->right;
				delete root;
				return temp;
			}
			//3 case having both children
				//first search for inorder sucessor
				Node *replace=root->right;
				while(replace->left!=NULL)
				{
					replace=replace->left;
				}
				// replace root data with repalce data
				root->data=replace->data;
				root->right=deleteBST(root->right,replace->data);
				return root;
		}

		
		else      						// it must be present at right subtree
		{
			root->right=deleteBST(root->right,data);
			return root;
		}
	}
int main() {
	int t;
	cin>>t;// Number of testcase
	while(t--)
	{
	int n1,n2,arr1[1000],arr2[1000];
	cin>>n1;
	for(int i=0;i<n1;i++)
	cin>>arr1[i];
	cin>>n2;
	for(int i=0;i<n2;i++)
	cin>>arr2[i];
	Node *root=NULL;
	root=Build(arr1,n1);
//	preorder(root);
	for(int i=0;i<n2;i++)
	{
		root=deleteBST(root,arr2[i]);
	}
	cout<<endl;
	preorder(root);
	}
	return 0;
}