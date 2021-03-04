/*
INPUT
8 3 2 7 10 9 11 -1
OUTPUT
2 3 7 8 9 10 11 
Not present
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
node *InsertInBST(node *root,int data)
{
    if(root==NULL)
    return new node(data);  // create a new node

    if(root->data>=data)
        root->left=InsertInBST(root->left,data);
    else
        root->right=InsertInBST(root->right,data);

     return root;   
}



node *buildBST(node *root)
{
     int val;
    cin>>val;
    while(val!=-1)
    {
        root=InsertInBST(root,val);
        cin>>val;
    }
    return root;    
}

void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool isPresent(node *root,int key)
{
    if(root==NULL)
    return false;
    if(root->data==key)
    return true;
    if(key<root->data)
        return isPresent(root->left,key);
    else 
        return isPresent(root->right,key);
}

int main()
{
    node *root=buildBST(NULL);
    inorder(root);
    if(isPresent(root,12))
        cout<<"Present";
        else
        cout<<"Not present";
    
}
