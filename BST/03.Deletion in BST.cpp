/*   
1) Node to be deleted is leaf: Simply remove from the tree. 
              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
       
2) Node to be deleted has only one child: Copy the child to the node and delete the child 

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. 
Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
 

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80       
                
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

void preorder(node *root)
{
    if(root==NULL)
    return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
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

node *deleteNode(node *root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->data>key)
    {
        root->left=deleteNode(root->left,key);
        return root;
    }
    if(root->data==key)
    {
        // Node is founded which need to be deleted
        // case 1. Node with 0 child
        if(root->left==NULL and root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2. With 1 child
        //      2.a With 1 left child only

        if(root->left!=NULL and root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }

        //   2.b With 1 right child only

        if(root->left==NULL and root->right!=NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
         // Case 2. With 2 child
         // find minimum element in right subtree and replace with thier value and delete that node

         node *replace=root->right;
         while(replace->left!=NULL)
            replace=replace->left;
         root->data=replace->data;
         root->right=deleteNode(root->right,replace->data);
         return root;   
    }
    if(root->data<key)
    {
        root->right=deleteNode(root->right,key);
        return root;
    }
    return root;
}

int main()
{
    node *root=buildBST();
    preorder(root);
    deleteNode(root,30);
    cout<<"\n";
      preorder(root);
}
