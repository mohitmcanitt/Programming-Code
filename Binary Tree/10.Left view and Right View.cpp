

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

node *buildTree()
{
    int ele;
    cin>>ele;
    if(ele==-1)
    {
        return NULL;
    }
    node *root=new node(ele);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void printRightView(node *root,int level,int &maxlevel)
{
    if(root==NULL)
    return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    printRightView(root->right,level+1,maxlevel);
    printRightView(root->left,level+1,maxlevel); 
}


// void printleftView(node *root)
// {
//     if(root==NULL)
//            return;
//     queue<node *>q;
//     q.push(root);
//     while(!q.empty())
//     {
//         int n=q.size();
//         for(int i=1;i<=n;i++)
//         {
//             queue<node*>temp=q.front();
//             q.pop();
//             if(i==n)
//                 cout<<temp->data;
//             if(temp->left)
//                    q.push(temp->left);
//             if(temp->right)
//                     q.push(temp->right);
//         }
//     }   
// }       


void printleftView(node *root,int level,int &maxlevel)
{
    if(root==NULL)
    return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    
    printleftView(root->left,level+1,maxlevel); 
    printleftView(root->right,level+1,maxlevel);
}

// void printleftView(node *root)
// {
//     if(root==NULL)
//            return;
//     queue<node *>q;
//     q.push(root);
//     while(!q.empty())
//     {
//         int n=q.size();
//         for(int i=1;i<=n;i++)
//         {
//             queue<node*>temp=q.front();
//             q.pop();
//             if(i==1)
//                 cout<<temp->data;
//             if(temp->left)
//                    q.push(temp->left);
//             if(temp->right)
//                     q.push(temp->right);
//         }
//     }   
// }       

int main() {

    node *root=buildTree();
    int left_maxlevel=-1;
    cout<<"Left View of a tree : ";
    printleftView(root,0,left_maxlevel);
    cout<<endl;
    cout<<"Right View of a tree : ";
    int right_maxlevel=-1;
    printRightView(root,0,right_maxlevel);
}
/*
INPUT
4 5 -1 -1 2 3 6 -1 -1 7 -1 -1 1 -1 -1
OUTPUT
Left View of a tree : 4 5 3 6 
Right View of a tree : 4 2 1 7

*/
