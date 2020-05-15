/*
Given preorder and inorder create the tree

Input Format
Enter the size of the preorder array N then add N more elements and store in the array denoting the preorder traversal of the tree. Then enter the size of the inorder array M and add M more elements and store the inorder traversal of the array.

Constraints
1 <= N, M <= 10^4

Output Format
Display the tree using a modified preorder function. For each node , first print its left child's data , then the data of the root itself , then the data of its right child. Do this for each node in a new line in preorder manner. If one of the children does not exist print END in its place. Refer to the sample testcase.

Sample Input
3
1 2 3
3
3 2 1
Sample Output
2 => 1 <= END
3 => 2 <= END
END => 3 <= END
Explanation
The above tree looks like

         1
       /
     2
   /
 3 */
#include<iostream>
#include <queue> 
#include<stack>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *BuildBST(int *inord,int *pre,int s,int e)
	{
		if(s>e)			// base case
		return NULL;
		static int i=0; // since preoder will be travrese only once
		Node *root=new Node(pre[i]);
		int index=-1;
		for(int j=s;j<=e;j++)
		{
			if(pre[i]==inord[j])
			{
				index=j;
				break;
			}
		}
		i++;
		root->left=BuildBST(inord,pre,s,index-1);
		root->right=BuildBST(inord,pre,index+1,e);
		return root;
	}
	void modifiedpreorder(Node *root)
	{
		if(root==NULL)
		return;
		
		if(root->left)
		cout<<root->left->data<<" => ";
		else
		cout<<"END => ";
		cout<<root->data<<" ";
		if(root->right)
		cout<<"<= "<<root->right->data;
		else
		cout<<"<= END";
		cout<<endl;
		modifiedpreorder(root->left);
		modifiedpreorder(root->right);

	}
	void preoder(Node *rot)
	{
		if(rot==NULL)
		return;
		cout<<rot->data<<" ";
		preoder(rot->left);
		preoder(rot->right);
	}
int main()
	{
		int n,pre[1000];
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>pre[i];
		int m,inord[1000];
		cin>>m;
		for(int i=0;i<m;i++)
		cin>>inord[i];
		Node *root=NULL;
		root=BuildBST(inord,pre,0,n-1);
		//preoder(root);
		modifiedpreorder(root);
		return 0;
	}