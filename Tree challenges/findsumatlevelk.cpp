/*
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output
20
Explanation
Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2
Sum at Level 2 = 3 + 4 + 6 + 7 = 20 */
#include <iostream>
using namespace std;
class Node{
private:
   public:
    int data;
    Node** children;
    int child_count;

    Node (int d){
        data=d;
        children=NULL;
        child_count=0;
    }
};

Node* InputForGenricTree(){
    //Enter Node Data 
    int d; cin>>d;
    Node* nn=new Node(d);
    // Enter no of children for node#
    int c; cin>>c;
    nn->child_count=c;
    nn->children=new Node*[c];
    for (int i=0;i<c;i++){
        nn->children[i]=InputForGenricTree();
    }
    return nn;
}
/*void PrintPreOrder(Node* rt){
    if (rt==NULL) return;
    cout<<rt->data<<" ";
    for (int i=0;i<rt->child_count;i++){
        PrintPreOrder(rt->children[i]);
    }
}*/
int findsum(Node *root,int k)
	{
		static int  sum=0;
		if(root==NULL)
		return 0;
		if(k==0)
		sum=sum+root->data;
		for (int i=0;i<root->child_count;i++){
        	findsum(root->children[i],k-1);
    }
		return sum;
	}
int main() {
   Node* root=NULL;
   root=InputForGenricTree();
   int k;
   cin>>k;
   cout<<findsum(root,k);
  // PrintPreOrder(root);
}