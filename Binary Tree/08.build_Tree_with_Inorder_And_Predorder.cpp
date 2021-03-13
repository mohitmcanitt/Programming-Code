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

node *build_Tree_with_Inorder_And_Predorder(vector<int>preorder,vector<int>inorder,int start,int end)
{
    if(start>end)
    return NULL;
    static int i=0;
    node *root=new node(preorder[i]);
    int index=-1;
    for(int k=start;k<=end;k++)
    {
        if(preorder[i]==inorder[k])
        {
            index=k;
            break;
        }
    }
    i++;
    root->left=build_Tree_with_Inorder_And_Predorder(preorder,inorder,start,index-1);
    root->right=build_Tree_with_Inorder_And_Predorder(preorder,inorder,index+1,end);
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
    vector<int>preorder={1,2,3,4,8,5,6,7};
    vector<int>inorder={3,2,8,4,1,6,7,5};

    node *root=build_Tree_with_Inorder_And_Predorder(preorder,inorder,0,inorder.size()-1);
    levelordertraversal(root);
}
/*
OUTPUT
1 
2 5 
3 4 6 
8 7 

*/
