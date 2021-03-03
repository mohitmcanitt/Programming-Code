/*
INPUT
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
OUTPUT
Key is present
*/


#include <bits/stdc++.h>
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

bool findkey(node *root,int key)
{
    if(root==NULL)
    return false;
    if(root->data==key)
    return true;
    // First check in left tree
    bool filc=findkey(root->left,key);  // filc->find in left child
    if(filc)
    return true;
    // then check in right tree
    bool firc=findkey(root->right,key);  // firc-> find in right child
    if(firc)
    return true;
    else
    return false;
}

int main()
{
    node *root=buildTree();
    bool ispresent=findkey(root,3); // check 3 is present in the tree or not
    if(ispresent)
    cout<<"Key is present";
    else
    cout<<"Key is not present";
}


