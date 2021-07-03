#include <iostream>
#include<vector>
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

void leftboundary(node *root,vector<int>&v)
    {
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL) // to skip leaves nodes
            return;
        v.push_back(root->data);
        if(root->left)
            leftboundary(root->left,v);
        else 
            leftboundary(root->right,v);
        
    }
    
    void rightboundary(node *root,vector<int>&v)
    {
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL) // to skip leaves nodes
            return;    
        if(root->right)    
        rightboundary(root->right,v);
        else 
        rightboundary(root->left,v);    

        v.push_back(root->data);
    }
    
    
    void printleaves(node *root,vector<int>&v)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL)
        {
             v.push_back(root->data);
             return;
        }
         printleaves(root->left,v);
         printleaves(root->right,v);
    }
    vector <int> printBoundary(node *root)
    {
        //Your code here
           vector<int>ans;
        if(root==NULL)
            return ans;
     
        
        ans.push_back(root->data);
        
        leftboundary(root->left,ans);
        printleaves(root,ans);
        rightboundary(root->right,ans);
        
        return ans;
    }


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




int main() {
    node *root=buildTree();
    vector<int>v=printBoundary(root);
    for(auto x:v)
        cout<<x<<" ";
}
// Input  3 4 -1 5 -1 -1 6 1 -1 -1 -1
// Output  3 4 5 6 1 
