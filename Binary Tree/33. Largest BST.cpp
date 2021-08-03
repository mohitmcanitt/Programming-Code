#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class var{
    public:
    int min;
    int max;
    int size;
    bool isBST;
};

node *build()
{
    int val;
    cin>>val;
    if(val==-1)
    return NULL;

    node* root=new node(val);
    root->left=build();
    root->right=build();

    return root;
}

var helper(node *root)
{
    var v;
    if(root==NULL)
    {
        v.min=INT_MAX;
        v.max=INT_MIN;
        v.size=0;
        v.isBST=true;
    }
    if(root->left==NULL and root->right==NULL)
    {
        v.min=root->data;
        v.max=root->data;
        v.size=1;
        v.isBST=true;
    }
    else if(root->left!=NULL and root->right==NULL)
    {
        var ls=helper(root->left);
        if(root->data>ls.max and ls.isBST)
        {
            v.size=1+ls.size;
            v.isBST=true;
        }
        else
        {
            v.size=ls.size;
            v.isBST=false;
        }
        v.min=(root->data,ls.min);
        v.max=(root->data,ls.max);
    }
    else if(root->left==NULL and root->right!=NULL)
    {
        var rs=helper(root->right);
        if(root->data<rs.min and rs.isBST)
        {
            v.size=1+rs.size;
            v.isBST=true;
        }
        else{
            v.size=rs.size;
            v.isBST=false;
        }
        v.min=(root->data,rs.min);
        v.max=(root->data,rs.max);
    }
    else
    {
        var ls=helper(root->left);
        var rs=helper(root->right);

        if(root->data>ls.max and root->data<rs.min and ls.isBST and rs.isBST)
        {
            v.size=1+ls.size+rs.size;
            v.isBST=true;
        }
        else
        {
            v.size=max(ls.size,rs.size);
            v.isBST=false; 
        }
        v.min=(root->data,min(ls.min,rs.min));
        v.max=(root->data,min(ls.max,rs.max));
    }
    return v;
}
                                                        

int BSTsize(node *root)
{
    var v=helper(root);
    return v.size;
}

void level(node *root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(i==n-1)
                cout<<endl;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);        
        }

    }
}


int main() {
    node *root=build();
    level(root);
    cout<<endl;
    cout<<BSTsize(root);
}
