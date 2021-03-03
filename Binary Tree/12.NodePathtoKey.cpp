/*
INPUT
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
OUTPUT
10 11 5 1 
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

vector<node*>v;
bool find(node *root,int key)
{
    if(root==NULL)
    return false;
    if(key==root->data)
    {
        v.push_back(root);
        return true;
    }
    bool filc=find(root->left,key);
    if(filc)
    {
        v.push_back(root);
        return true;
    }
    bool firc=find(root->right,key); //firc: find in left child
    if(firc)
     {
        v.push_back(root);
        return true;
    }
    else
    return false;
}
void kthlevelprinting(node *root,int k,node *blocker)
{
    if(root==NULL or k<0 or root==blocker) 
    return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    kthlevelprinting(root->left,k-1,blocker);
    kthlevelprinting(root->right,k-1,blocker);
}

void print_all_nodes_at_KthUnitDistance_from_target_node(node *root,int target,int k)
{
    bool x=find(root,target); // create a vector of path between target node to root;
    for(int i=0;i<v.size();i++)
    {
        node *blocker=NULL;
        if(i!=0)
        blocker=v[i-1];
        kthlevelprinting(v[i],k-i,blocker);  
    }
}


int main() {
    node *root=buildTree();
    print_all_nodes_at_KthUnitDistance_from_target_node(root,4,2);

}
