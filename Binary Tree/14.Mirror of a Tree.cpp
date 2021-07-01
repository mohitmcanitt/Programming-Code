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

void mirror(node *root)
{
    if(root==NULL)
    return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);

}
   
    

int main() {
    node *root=buildTree();
    cout<<"Before Mirrioring \n";
    LevelOrder(root);
    mirror(root);

    cout<<"After Mirrioring \n";
    LevelOrder(root);
}
/*
INPUT
5 3 2 -1 -1 4 -1 -1 6 -1 -1
OUTPUT
Before Mirrioring 
5 
3 6 
2 4 
After Mirrioring 
5 
6 3 
4 2 
*/
