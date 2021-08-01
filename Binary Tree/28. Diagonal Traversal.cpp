void helper(TreeNode* root,int slope,map<int,vector<int>>&m)
{
    if(root==NULL)
        return;
    m[slope].push_back(root->val);    
    helper(root->left,slope+1,m);
    helper(root->right,slope,m);   
}

vector<int> solve(TreeNode* root) {
    vector<int>ans;
    if(root==NULL)
        return ans;
    map<int,vector<int>>m;
    helper(root,0,m);
    for(auto x:m)
        for(auto y:x.second)
            ans.push_back(y);
    return ans;        
}
