   vector<int> topView(Node * root) {
        vector<int>ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            Node *temp=it.first;
            int hd=it.second;
            
            if(m.find(hd)==m.end())
            m[hd]=temp->data;
            
            if(temp->left)
                q.push({temp->left,hd-1});
            if(temp->right)
                q.push({temp->right,hd+1});
        }
        for(auto x:m)
            ans.push_back(x.second);
        return ans;

    }
