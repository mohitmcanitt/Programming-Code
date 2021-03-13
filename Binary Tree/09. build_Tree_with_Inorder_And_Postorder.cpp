#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

node *build_Tree_with_Inorder_And_Postorder(vector<int>postorder,vector<int>inorder,int start,int end)
{
    if(start>end)
    return NULL;
    static int i=postorder.size()-1;
    node *root=new node(postorder[i]);
    int index=-1;
    for(int k=start;k<=end;k++)
    {
        if(postorder[i]==inorder[k])
        {
            index=k;
            break;
        }
    }
    i--;
    //Make the created tree as right child of root first and then left. 
    root->right=build_Tree_with_Inorder_And_Postorder(postorder,inorder,index+1,end);
    root->left=build_Tree_with_Inorder_And_Postorder(postorder,inorder,start,index-1);
    return root;

}

void levelordertraversal(node *root)
{
    if(root==NULL)
    return;
    queue<node*>q;
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
                q.push(temp->right) ;
        }
    }
}

int main() {
    vector<int>postorder={8, 4, 5, 2, 6, 7, 3, 1};
    vector<int>inorder={4, 8, 2, 5, 1, 6, 3, 7};
    node *root=build_Tree_with_Inorder_And_Postorder(postorder,inorder,0,inorder.size()-1);
    levelordertraversal(root);
}
/*
          1
       /     \
     2        3
   /    \   /   \
  4     5   6    7
    \
      8

*/
