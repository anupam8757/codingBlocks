#include <iostream>
#include <list>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
class Solution{
    node* prev;
    node* head;

    void b2ll(node* root){
        if(root == NULL){
            return;
        }
        b2ll(root->left);
        if(prev == NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        b2ll(root->right);
    }
};
int main(){
    node* root = buildTree();
    print(root);
return 0;
}


