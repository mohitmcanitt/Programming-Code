#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

void insert(node *&root,int val)
{
    
    if(root==NULL)
    {
        node* new_node=new node(val);
        root=new_node;
        return;
    }
    if(val<root->data)
        insert(root->left,val);
    else
        insert(root->right,val);    
}

void print(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);    
}

int main() {
    node *root=NULL;
    insert(root,10);
    insert(root,20);
    insert(root,5);
    print(root);


}
