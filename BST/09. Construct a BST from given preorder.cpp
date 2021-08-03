/*
Method : ( O(n2) time complexity ) 
The first element of preorder traversal is always root. 
We first construct the root.
Then we find the index of the first element which is greater than the root. 
Let the index be ‘i’. The values between root and ‘i’ will be part of the left subtree, 
and the values between ‘i+1’ and ‘n-1’ will be part of the right subtree. Divide given pre[] at index “i” and recur for left and right sub-trees. 

For example in {10, 5, 1, 7, 40, 50}, 10 is the first element, so we make it root.
Now we look for the first element greater than 10, we find 40. So we know the structure of BST is as following. 

             10
           /    \
          /      \
  {5, 1, 7}       {40, 50}

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

int find_greater(vector<int>&v,int s,int e,int key)
{
    for(int i=s;i<=e;i++)
        if(v[i]>key)
            return i;
    return -1;        

}

Node *buildTree(vector<int>&v,int s,int e)
{
    if(s>e)
    return NULL;

    Node *root=new Node(v[s]);
    int index=find_greater(v,s+1,e,v[s]);
    if(index==-1)
       root->left=NULL;
    else    
    root->left=buildTree(v,s+1,index-1);
    if(index==-1)
        root->right=NULL;
    else    
    root->right=buildTree(v,index,e);

    return root;
}

void printBST(Node *root)
{
    if(root==NULL)
        return;
    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);    
}

int main() {
    vector<int>v={10,5,1,7,40,50};
    Node *root=buildTree(v,0,v.size()-1);
    printBST(root);
}
