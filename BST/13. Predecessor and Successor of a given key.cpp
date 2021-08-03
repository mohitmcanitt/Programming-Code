// https://www.youtube.com/watch?v=lQIXz5NJYLs
Node* preSolve(Node *root)
{
   Node *temp=root->left;
   while(temp->right)
    temp=temp->right;
    return temp;
}
Node *sucSolve(Node *root)
{
    Node *temp=root->right;
    while(temp->left)
        temp=temp->left;
    return temp;    
        
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return;
    if(root->key==key)
    {
        if(root->left) pre=preSolve(root);
        if(root->right) suc=sucSolve(root);
        
        return;
    }
    if(root->key<key) // right jaa rhe hai too pre mai store kro
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else if(root->key>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    
}
