#include <iostream>
using namespace std;

class node{
     public:
    int data;
    node* left;
    node *right;
   
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *buildTree()
{
    int val;
    cin>>val;
    if(val==-1)
        return NULL;
    node *root=new node(val);
    root->left=buildTree();
    root->right=buildTree();
    return root;    
}

void printTree(node *root)
{
    if(root==NULL)
    return;
    // Print root value and its subtree

    cout<<root->data;
    printTree(root->left);
    printTree(root->right);
}

int main() {
    node *root=buildTree();
    printTree(root);
}
// Input  3 4 -1 5 -1 -1 6 1 -1 -1 -1
// Output  3 4 5 6 1 
