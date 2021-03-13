// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

/*
INPUT
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
OUTPUT
Tree is not balanced
*/

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

int height(node *root)
    {
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(node* root) // 0(n^2)
    {
        if(root==NULL)
            return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1 and isBalanced(root->left) and isBalanced(root->right) )
            return true;
       
           return false;
       
    }
// class HBPair{

//     public:
//     int height;
//     bool isBalance;
// };


// HBPair isBalanced(node* root) // o(n)
// {
//         HBPair p;
//         if(root==NULL)
//         {
//             p.height=0;
//             p.isBalance=true;
//             return p;
//         }
//         HBPair left=isBalanced(root->left);
//         HBPair right=isBalanced(root->right);
//         p.height=max(left.height,right.height)+1;
//         if(abs(left.height-right.height) and left.isBalance and right.isBalance)
//             p.isBalance=true;
//             else
//             p.isBalance=false;
//             return p;
            
       
//     }

int main() {
    node *root=buildTree();
   if(isBalanced(root))
    cout<<"Tree is Balanced\n";
    else
    cout<<"Tree is not balanced\n";

}
