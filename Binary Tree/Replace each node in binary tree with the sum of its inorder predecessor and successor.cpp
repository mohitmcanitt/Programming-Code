/*         1        
         /   \      
        2      3     
      /   \   /  \
    4     5  6    7  
    
           27        
         /   \      
        11      13     
      /   \   /  \
    4     5  6    7   
    
 https://www.geeksforgeeks.org/replace-node-binary-tree-sum-inorder-predecessor-successor/  
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



void levelorderPrintingTree(node *root)  // for getting each level in different lines
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
                     cout<<temp->data<<" ";
                    if(temp->left)
                    q.push(temp->left);
                    if(temp->right)
                    q.push(temp->right);
                }
    }
}
int sum(node *root)
{
    if(root==NULL)
    return 0;
    return root->data+sum(root->left)+sum(root->right);
}
void sumreplacement(node *root)
{
    if(root==NULL)
    return;
    if(root->left==NULL and root->right==NULL)
	return ;
    root->data=sum(root->left)+sum(root->right);
    sumreplacement(root->left);
    sumreplacement(root->right);
}



int main() {
    node *root=buildTree();
   sumreplacement(root);
    levelorderPrintingTree(root);

}
