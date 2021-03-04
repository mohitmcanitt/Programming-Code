/*
INPUT
3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
OUTPUT
3 
5 1 
6 2 0 8 
7 4 
Path to 2 is 3 5 2 
Path to 4 is 3 5 2 4 
Lowest comman ancestor of  2 4 is 2

*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;
    node(int d)
    {
        this->data=d;
        left=NULL;
        right=NULL;
    }
};
node *buildTree()
{
    int ele;
    cin>>ele;
    if(ele==-1)
    return NULL;
    node *root=new node(ele);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void levelOrderTraversal(node *root)
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
                q.push(temp->right);    
           }
        }
}
bool findpath(node *root,int key,vector<node*>&v)
{
    if(root==NULL)
    return false;
     v.push_back(root);
    if(root->data==key)
     return true;
    if(findpath(root->left,key,v))
        return true;
    if(findpath(root->right,key,v))
       return true;
    else
    {
        v.pop_back();
        return false;
    }
}

node* address_lca(node *root,int a,int b)
{   vector<node*>a_path;
    findpath(root,a,a_path);

    vector<node*>b_path;
    findpath(root,b,b_path);

    cout<<"Path to "<<a<<" is ";
    for(auto x:a_path)
        cout<<x->data<<" ";
    cout<<endl;
     cout<<"Path to "<<b<<" is ";
    for(auto x:b_path)
        cout<<x->data<<" ";  
         
    cout<<"\nLowest comman ancestor of  "<<a<<" "<<b<<" is ";
   int i=0;
        while(i<a_path.size() and i<b_path.size())
        {
            if(a_path[i]->data!=b_path[i]->data)
                return a_path[i-1];
            i++;
        }
        if(i==a_path.size())
            return a_path[a_path.size()-1];
        else
            return b_path[b_path.size()-1];   
}

int main()
{
    node *root=buildTree();
    levelOrderTraversal(root);
    node *address=address_lca(root,2,4);
    cout<<address->data;

}
