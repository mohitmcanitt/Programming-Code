/*
INPUT : 1 2 7 -1 -1 6 -1 -1 3 5 -1 -1 4 -1 -1
OUTPUT :  1 
          2 3 
          4 5 6 7 

*/


#include <iostream>
#include<queue>
using namespace std;

class node{
     public:
    int data;
    node* left;
    node *right;
   
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *buildTree()
{
    int val;
    cin>>val;
    if(val==-1)
        return NULL;
    node *root=new node(val);
    root->left=buildTree();
    root->right=buildTree();
    return root;    
}

int height(node *root)
{
    if(root==NULL)
        return 0;
     int lh=height(root->left);
    int rh=height(root->right);

    return 1+max(lh,rh);
}

void printlevel(node *root,int level,string s)
{
    if(root==NULL)
        return ;
    if(level==1)   
        {
            cout<<root->data<<" ";
            return;
        }
    if(s=="even")     
    {
          printlevel(root->left,level-1,s);
          printlevel(root->right,level-1,s);
    }
 
    else
    {
        printlevel(root->right,level-1,s);
        printlevel(root->left,level-1,s);
    }
}



void zigzag(node *root)
{
    if(root==NULL)
        return;
     int hgt=height(root);
   for(int i=1;i<=hgt;i++)
   {
         i%2==0?printlevel(root,i,"even"):printlevel(root,i,"odd");
         cout<<"\n";
   }
     

}

void optimizedZigZag(node *root)
{
    if(root==NULL)
        return;
    stack<node *>odd;
    stack<node *>even;

    odd.push(root);

    while(!odd.empty() or !even,empty())
    {

        while(!odd.empty())
        {
            node *temp=odd.top();
            odd.pop();
            cout<<temp->data;

            if(temp->right)
                even.push(temp->right);
            if(temp->left)
                even.push(temp->left);  
        }
        while(!even.empty())
        {
            node *temp=even.top();
            even.pop();
            cout<<temp->data;

            if(temp->left)
                odd.push(temp->left);
            if(temp->right)
                odd.push(temp=->right);    
        }
              
    }    

}

int main() {
    node *root=buildTree();
    //zigzag(root);
    optimizedZigZag(root);
}
