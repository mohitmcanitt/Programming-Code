// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// output 18

// problem statement
// find the largest sum of subset of nodes in a binary such that
// if a node is included in the sum then its parent and children can be added
// in target sum



#include<iostream>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        left=NULL;
        right=NULL;
        data=d;
    }
};

node* buildTree()
{
    int val;
    cin>>val;
    if(val==-1)
        return NULL;
    node *new_node=new node(val);
    new_node->left=buildTree();
    new_node->right=buildTree();    
    return new_node;
}

void printTree(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);    
}

// for each node, we will maintain two value
// p.first=include and p.second=exclude
// for include means we can all add the current root node data and exculde data 
// of their children like p.first=root->data+LS.second+RS.second;

// for exlude means we can add max value of include and exclude from left
// child and right child  p.second= max(LS.first,LS.second)+max(LS.first,LS.second)

pair<int,int>subsetSum(node *root)
{
    pair<int,int>p;//p.first include, p.second exclude

    if(root==NULL)
        {
            p.first=0;
            p.second=0;
            return p;
        }
    pair<int,int>LS = subsetSum(root->left);
    pair<int,int>RS = subsetSum(root->right);

    p.first=root->data+LS.second+RS.second;
    p.second=max(LS.first,LS.second)+max(RS.first,RS.second);

    return p;
}

int main()
{
  node *root=buildTree();
  pair<int,int>p=subsetSum(root);
  cout<<max(p.first,p.second);
}
