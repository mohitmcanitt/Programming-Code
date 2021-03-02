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

void preorderPrintingTree(node *root)  //root  Left Right
{
    if(root==NULL)
    return;
    // Print root value and its subtree

    cout<<root->data<<" ";
    preorderPrintingTree(root->left);
    preorderPrintingTree(root->right);
}

void inorderPrintingTree(node *root)  // Left root Right
{
    if(root==NULL)
    return;
    // Print root value and its subtree
    inorderPrintingTree(root->left);
     cout<<root->data<<" ";
    inorderPrintingTree(root->right);
}
void postorderPrintingTree(node *root)  // Left Right root
{
    if(root==NULL)
    return;
    // Print root value and its subtree
    postorderPrintingTree(root->left);
    postorderPrintingTree(root->right);
    cout<<root->data<<" ";
   ;
}

int main() {
    node *root=buildTree();
    cout<<"Preorder Printing ";
    preorderPrintingTree(root);
    cout<<endl;
    cout<<"Inorder Printing ";
    inorderPrintingTree(root);
    cout<<endl;
    cout<<"Preorder Printing ";
    postorderPrintingTree(root);
}

/*
Input : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Output: 

Preorder Printing 8 10 1 6 9 7 3 14 13 
Inorder Printing 1 10 9 6 7 8 3 13 14 
Preorder Printing 1 9 7 6 10 13 14 3 8

*/
