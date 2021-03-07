/*
 We will maintain two pointer head and tail

 for a particular node
 head == tail of left subtree
 tail  == head of right subtree

 case 1. if right subtree doesn,t exist 
         tail will be root itself and head will be (head of left subtree)
          tail of left subtree will point root

case 2.  If left subtree doesn't exist 
        head will be root itself and tail will be(tail of right subtree)
        root->right will point head of right subtree

case 3. if left tree and right tree exists then
        head ==> (left subtree head) and tail==> (right subtree tail) 
        tail of left subtree will point root
        root->right will point head of right subtree
*/


#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};


class linkList{
    public:
    node *head;
	node *tail;
};
node *insertIntoBST(node *root,int val)
{
    if(root==NULL)
    return new node(val);

    if(root->data>val)
        root->left=insertIntoBST(root->left,val);
    else if(root->data<val)
       root->right=insertIntoBST(root->right,val);
    return root;
}


node *buildBST()
{
    int val;
    cin>>val;
    if(val==-1)
    return NULL;
    node *root=NULL;
    while(val!=-1)
    {
       root=insertIntoBST(root,val);
        cin>>val;
    }
    return root;
}


linkList flatten(node *root)
{
    linkList l;
    if(root==NULL)  
    {
        l.head=NULL;
        l.tail=NULL;
        return l;
    }
    // for leaf node head and tail will be root itself
    if(root->left==NULL and root->right==NULL)
    {
        l.head=root;
        l.tail=root;
        return l;
    }
    // if right subtree doesn,t exist 
    // tail will be root itself and head will be (head of left subtree)
    // tail of left subtree will point root
     if(root->left!=NULL and root->right==NULL)
    {
         linkList leftLL=flatten(root->left);
         leftLL.tail->right=root;
         l.head=leftLL.head;
         l.tail=root;
          return l;
    }

    // If left subtree doesn't exist 
    // head will be root itself and tail will be(tail of right subtree)
    // root->right will point head of right subtree
     if(root->left==NULL and root->right!=NULL)
    {
         linkList rightLL=flatten(root->right);
         root->right=rightLL.head;
         l.head=root;
         l.tail=rightLL.tail;
        return l;
    }
    // if left tree and right tree exists then
    // head ==> (left subtree head) and tail==> (right subtree tail) 
    // tail of left subtree will point root
    // root->right will point head of right subtree

  
        linkList leftt=flatten(root->left);
        linkList rightt=flatten(root->right);

        leftt.tail->right=root;
        root->right=rightt.head;

        l.head=leftt.head;
        l.tail=rightt.tail;
        return l;
  
}

int main()
{
    node *root=buildBST();
    linkList ob=flatten(root);
    node *temp1=ob.head;
    node *temp2=ob.tail;
    while(temp1!=temp2)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->right;
    }
}
