/*
INPUT
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

OUTPUT
Levelorder Traversal 
1 
2 3 
4 5 6 7 
Preorder Traversal 1 2 4 5 3 6 7 
Inorder Traversal 4 2 5 1 6 3 7 
Postorder Traversal 4 5 2 6 7 3 1 


Algo:

1. preorder
    a. Create a stack.
    b. Push root node 
    c. Pop top element ,print it and 
        --> push right child first and then left child of popped element;
    d. Repeat step c until stack is not empty    


2. Inorder  
    a. Create a stack and intialize a current variable with root value
    b. Itearte until stack is not empty and curr is  null
    c. Inside loop , push curr and set curr->current left until before it encounter NULL
    d. Once it encounter NULL , pop top elment ,print it and curr=popped->right;
    e. Repeat step c and d,

3. Postorder
    a. Create a stack.
    b. Push root node 
    c. Pop top element ,store it in another stack and 
        --> push left child first and then right child of popped element;
    d. Repeat step c until stack is not empty    
    e. Now print Stack.. bcoz our answer is stored in reversed manner
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;
    node(int data)
    {
        this->data=data;
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

void levelorder(node *root)
{

    cout<<"Levelorder Traversal \n";
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

void preorder(node *root)
{
    cout<<"Preorder Traversal ";
    if(root==NULL)
    return;
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node *temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        
           if(temp->right)
            s.push(temp->right); 
            if(temp->left)
            s.push(temp->left);
    }
    cout<<endl;
}
void inorder(node *root)
{
    cout<<"Inorder Traversal ";
    stack<node*>s;
    node *curr=root;
    while(!s.empty() or curr!=NULL)
    {
        if(curr==NULL)
        {
            node *temp=s.top();
            cout<<temp->data<<" ";
            s.pop();
            curr=temp->right;
        }
        else
        {
            s.push(curr);
            curr=curr->left;
        }
    }
    cout<<endl;
}


void postorder(node *root)
{
    cout<<"Postorder Traversal ";
    if(root==NULL)
    return;
    stack<node*>s;
    stack<int>ans;
    s.push(root);
    while(!s.empty() )
    {
        node *temp=s.top();
        s.pop();
        ans.push(temp->data);
         if(temp->left)
            s.push(temp->left);
           if(temp->right)
            s.push(temp->right); 
           
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
}


int main()
{
    node *root=buildTree();
    levelorder(root);
    preorder(root);
    inorder(root);
    postorder(root);
}
