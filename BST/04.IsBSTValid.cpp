  bool isBST(Node* root,int low=INT_MIN,int high=INT_MAX) 
    {
        // Your code here
        if(root==NULL)
            return true;
        if(root->data<=low or root->data>=high)
            return false;
        
        return isBST(root->left,low,root->data) and isBST(root->right,root->data,high);    
    }
