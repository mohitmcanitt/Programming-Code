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
int height(node *root)
{
    if(root==NULL)
    
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
void printkthlevel(node *root,int k)
{
    if(root==NULL)
    return;
    if(k==1)
    {
        
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}

void LevelOrder(node *root)
{
    int hgt=height(root);
    for(int k=1;k<=hgt;k++)
    {
        printkthlevel(root,k);
        cout<<endl;
    }
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
