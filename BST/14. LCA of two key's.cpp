Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL)
    return NULL;
    
    if(n1<root->data and n2<root->data) // agar search space both key ka either left or right ho to no prblm
        return LCA(root->left,n1,n2);
    if(n1>root->data and n2>root->data)
        return LCA(root->right,n1,n2);
    else
        return root;   // but agar ek left jaa rha hai or ek right jaa rha hai too prblm hai
    
}
