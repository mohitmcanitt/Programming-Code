// Leetcode problem number 100

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL)
            return true;
        if(p==NULL and q!=NULL)
            return false;
        if(p!=NULL and q==NULL)
            return false;
       
        if(p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right))
        return true;
        return false;
            
    }
