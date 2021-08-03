// https://www.youtube.com/watch?v=8AnntMKIWlQ  
void helper(Node *root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        helper(root->left,ans);
        ans.push_back(root->data);
        helper(root->right,ans);
    }
    int i=0;
    void inorder_traversal(Node *&root,vector<int>&inorder)
    {
        
        if(root==NULL)
            return;
        inorder_traversal(root->left,inorder);
        root->data=inorder[i];
        i++;
        inorder_traversal(root->right,inorder);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>inorder;
        helper(root,inorder);
        sort(begin(inorder),end(inorder));
        inorder_traversal(root,inorder);
        return root;
    }
