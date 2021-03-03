/*
INPUT
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
OUT{UT
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

vector<node*> pathtokey(node *root,int key)
{
    static vector<node*>treenodepath;
    if(root==NULL)
    return {};
    if(root->data==key)
     {
        treenodepath.push_back(root);
        return treenodepath;
    }
    // First check in left tree
    vector<node*>filc=pathtokey(root->left,key);  // filc->find in left child
    if(filc.size())     // if size is not zero
     {
        treenodepath.push_back(root);
        return treenodepath;
    }
    // then check in right tree 
    vector<node*>firc=pathtokey(root->right,key);  // firc-> find in right child
    if(firc.size())
    {
        treenodepath.push_back(root);
        return treenodepath;
    }
    else
    return {};
}

void printkthlevel(node *src,int k,node *blocker)
{
    if(src==NULL or k<0 or blocker==src)
    return;
    if(k==0)
    cout<<src->data<<" ";
    printkthlevel(src->left,k-1,blocker);
    printkthlevel(src->right,k-1,blocker);
}

void print_all_nodes_at_distance_k_from_a_given_node(node *root,int target,int dist)
{
    vector<node*>v=pathtokey(root,target); // path(node address) from given node(containing target value) to root node 
    for(int i=0;i<v.size();i++)
        printkthlevel(v[i],dist-i,i==0?NULL:v[i-1]);

}


int main()
{
    node *root=buildTree();
    print_all_nodes_at_distance_k_from_a_given_node(root,4,3);// print all node at 2 distance from node containing 4.
    
    
}
