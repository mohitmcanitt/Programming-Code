// create node with arr mid value
// To left of node (creater arr from start to mid-1
// To right of node (create arr from mid+1 to end

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node *buildBalancedTree(vector<int>v,int start,int end)
{
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    node *root=new node(v[mid]);
    root->left=buildBalancedTree(v,start,mid-1);
    root->right=buildBalancedTree(v,mid+1,end);
    return root;
}

void levelordertraversal(node *root)
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
            cout<<temp->data<<",";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }
    return;
}


int main() {
    vector<int>v={1,2,3,4,5,6,7,8};
    node *root=buildBalancedTree(v,0,v.size()-1);
    levelordertraversal(root);
}
