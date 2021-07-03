// letcode 129 : https://leetcode.com/problems/sum-root-to-leaf-numbers/

void helper(TreeNode* root,int &sum,int local_sum)
    {
        if(root==NULL)
            return;
        local_sum=local_sum*10+root->val;
        if(root->left==NULL and root->right==NULL)
        {
            sum+=local_sum;
            return;
        }
        helper(root->left,sum,local_sum);
        helper(root->right,sum,local_sum);
    }
    
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int local_sum=0;
        helper(root,sum,local_sum);
        return sum;
    }
