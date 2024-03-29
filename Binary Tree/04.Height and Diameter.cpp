#include <iostream>
#include<queue>
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

//The height of the binary tree is the longest path from root node to any leaf node in the tree
int height(node *root)
{
    if(root==NULL)
    return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    return 1+max(lheight,rheight);
}
//he diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
int diameter(node *root)
{
    if(root==NULL)
    return 0;
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(1+op1,max(op2,op3));
}
//Optimized O(n)
//pair<int,int>p;
// p.first ---> height;
// p.second --->diameter
pair<int,int> diameter(node *root)
{
    if(root==NULL)
    return make_pair(0,0);

    pair<int,int>left=diameter(root->left);
    pair<int,int>right=diameter(root->right);

    pair<int,int>p;
    
    p.first=max(left.first,right.first)+1;

    int op1=left.first+right.first;
    int op2=left.second;
    int op3=right.second;

    p.second=max(op1,max(op2,op3));
    return p;
}

int main() {
    node *root=buildTree();
   cout<<"Height of tree "<<height(root)<<endl;
   cout<<"Diameter of tree is "<<diameter(root)<<endl;

}
/*
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
OUTPUT

#include <iostream>
#include<queue>
using namespace std;

class node{
     public:
    int data;
    node* left;
    node *right;
   
…int main() {
    node *root=buildTree();
   cout<<"Height of tree "<<height(root)<<endl;
   cout<<"Diameter of tree is "<<diameter(root)<<endl;

}

/*
Input
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Output
Height of tree 4
Diameter of tree is 6
*/
