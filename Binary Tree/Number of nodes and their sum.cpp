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

int no_of_nodes(node *root)
{
    if(root==NULL)
        return 0;
    return 1+no_of_nodes(root->left)+no_of_nodes(root->right);    
}
int sum_of_nodes(node *root)
{
    if(root==NULL)
        return 0;
    return root->data+sum_of_nodes(root->left)+sum_of_nodes(root->right);
}



void levelorderprinting(node *root)
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

int main() {
    node *root=buildTree();
    cout<<"Data of tree is \n";
    levelorderprinting(root);
    cout<<"Number of nodes in the given tree is "<<no_of_nodes(root)<<endl;
    cout<<"Sum of all the nodes is "<<sum_of_nodes(root)<<endl;
    
}

/*
INPUT
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

OUTPUT
Data of tree is 
8 
10 3 
1 6 14 
9 7 13 
Number of nodes in the given tree is 9
Sum of all the nodes is 71

*/
