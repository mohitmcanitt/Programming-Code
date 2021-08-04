bool find(TreeNode* root,int target,vector<TreeNode*>&path)
    {
        if(root==NULL)
            return false;
        if(root->val==target)
        {
            path.push_back(root);
            return true;
        }
        bool filc=find(root->left,target,path);
        if(filc)
       {
            path.push_back(root);
            return true;
        }
        
        bool firc=find(root->right,target,path);
        if(firc)
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    void kthleveldown(TreeNode *root,TreeNode* blocker,int level,vector<int>&ans)
    {
        if(root==NULL or root==blocker or level<0)
            return;
        if(level==0)
        {
            ans.push_back(root->val);
            return;
        }
        kthleveldown(root->left,blocker,level-1,ans);
        kthleveldown(root->right,blocker,level-1,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int>ans;
        vector<TreeNode*>path;
        
        find(root,target->val,path);
        
        for(int i=0;i<path.size();i++)
        {
            TreeNode *blocker=NULL;
            if(i!=0)
                blocker=path[i-1];
            kthleveldown(path[i],blocker,K-i,ans);
        }
        return ans;
    }
