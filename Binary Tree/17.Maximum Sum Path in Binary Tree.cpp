/*
INPUT
10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
OUTPUT
MAXIMUM Sum Path is 42.
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
int helper(node *root,int &max_sum)
{
    if(root==NULL)
    return 0;

    // l and r store maximum path sum going through left and 
    // right child of root respectively 
    int leftSum=helper(root->left,max_sum);
    int rightSum=helper(root->right,max_sum);

     // Max path for parent call of root. This path must 
    // include at-most one child of root 

    int max_single=max(max(leftSum,rightSum)+root->data,root->data);

    // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 

    int max_top=max(max_single,root->data+leftSum+rightSum);

    // Store the Maximum Result. 
     max_sum=max(max_sum,max_top);
    return max_single;
}



int maximumSum(node *root)
{
    int max_sum=INT_MIN;
    helper(root,max_sum);
    return max_sum;
}

int main()
{
    node *root=buildTree();
    cout<<"Maximum sum from two node is "<<maximumSum(root);
    
}
