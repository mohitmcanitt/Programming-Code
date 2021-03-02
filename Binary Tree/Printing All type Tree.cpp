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

void preorderPrintingTree(node *root)  //root  Left Right
{
    if(root==NULL)
    return;
    // Print root value and its subtree

    cout<<root->data<<" ";
    preorderPrintingTree(root->left);
    preorderPrintingTree(root->right);
}

void inorderPrintingTree(node *root)  // Left root Right
{
    if(root==NULL)
    return;
    // Print root value and its subtree
    inorderPrintingTree(root->left);
     cout<<root->data<<" ";
    inorderPrintingTree(root->right);
}
void postorderPrintingTree(node *root)  // Left Right root
{
    if(root==NULL)
    return;
    // Print root value and its subtree
    postorderPrintingTree(root->left);
    postorderPrintingTree(root->right);
    cout<<root->data<<" ";
   ;
}

// void levelorderPrintingTree(node *root)  // Iterative O(n) also known as BFS
// {
//     if(root==NULL)
//     return;
//    queue<node *>q;
//     q.push(root);

//     while(!q.empty())
//     {
//          node *temp=q.front();
//             q.pop();
//             if(temp==NULL)
//                 continue;
//             cout<<temp->data<<" ";
//             q.push(temp->left);
//             q.push(temp->right);
//     }
// }

void levelorderPrintingTree(node *root)  // for getting each level in different lines
{
    if(root==NULL)
    return;
   queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
            node *temp=q.front();
            q.pop();
            if(temp==NULL)
                {
                    cout<<"\n";
                    
                    if(!q.empty())
                        q.push(NULL);
                }
                else
                {
                     cout<<temp->data<<" ";
                    if(temp->left)
                    q.push(temp->left);
                    if(temp->right)
                    q.push(temp->right);
                }
    }
}

void kthlevelprinting(node *root,int k) // Print node value at kth level.Assuming root is at 1st level
{
    if(root==NULL)
    return;
    if(k==1)
        {
            cout<<root->data<<" ";
            return;
        }
    kthlevelprinting(root->left,k-1);
    kthlevelprinting(root->right,k-1); 
    return;   
}
int height(node *root)  // Height of tree. Total Number of nodes between longest route from root node to leaf node
{
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}

void recursivelevelprinting(node *root)   // Print Level order tree using iteration in O(n^2)
{
    int hgt=height(root);
    for(int i=1;i<=hgt;i++)
    {
          kthlevelprinting(root,i);
          cout<<endl;
    }
}


int main() {
    node *root=buildTree();

    cout<<"Preorder Printing ";
    preorderPrintingTree(root);
    cout<<endl;

    cout<<"Inorder Printing ";
    inorderPrintingTree(root);
    cout<<endl;

    cout<<"Preorder Printing ";
    postorderPrintingTree(root);
    cout<<endl;

    cout<<"Levelorder Printing using iteration \n";
    levelorderPrintingTree(root);
    cout<<endl;

    cout<<"Kth Levelorder Printing ";
    kthlevelprinting(root,2);
    cout<<endl;

    cout<<"Levelorder Printing Using Recursion \n";
    recursivelevelprinting(root);
}

/*
INPUT:
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

OUTPUT:
Preorder Printing 8 10 1 6 9 7 3 14 13 
Inorder Printing 1 10 9 6 7 8 3 13 14 
Preorder Printing 1 9 7 6 10 13 14 3 8 
Levelorder Printing using iteration 
8 
10 3 
1 6 14 
9 7 13 

Kth Levelorder Printing 10 3 
Levelorder Printing Using Recursion 
8 
10 3 
1 6 14 
9 7 13 

*/
