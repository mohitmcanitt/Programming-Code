// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/   

vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<int>>m;
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>ans;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            unordered_map<int,multiset<int>>um;
            while(size--)
            {
                auto it=q.front();
                q.pop();
                TreeNode* temp=it.first;
                int dist=it.second;
                um[dist].insert(temp->val);
                if(temp->left)
                    q.push({temp->left,dist-1});
                if(temp->right)
                    q.push({temp->right,dist+1});                
            }
            for(auto x:um)
            {
                for(auto y:x.second)
                  m[x.first].push_back(y);
            }
        }
        
        for(auto x:m)
        {
            vector<int>v;
            for(auto y:x.second)
                v.push_back(y);
            ans.push_back(v);
        }
        return ans;
        
        
    }
