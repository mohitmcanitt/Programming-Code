#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        left=NULL;
        right=NULL;
        this->data=data;
    }
};

node *buildTree()
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

node *newMirror(node *root)
{
    if(root==NULL)
        return NULL;
    node *new_node=new node(root->data);
    new_node->left=newMirror(root->right);
    new_node->right=newMirror(root->left);
    return new_node;    
}
void print(node *root)
{
    if(root==NULL)
        return;
     queue<node *>q;
     q.push(root);
     while(!q.empty())
     {
         int n=q.size();
         for(int i=1;i<=n;i++)
           {
               node *temp=q.front();
               q.pop();
               cout<<temp->data<<" ";
               if(i==n)
                cout<<endl;
               if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);  
           } 
     }   
}

int main()
{
    node *root=buildTree();
    node *root1=newMirror(root);

    print(root);
    cout<<endl;
    print(root1);
}
