// https://practice.geeksforgeeks.org/viewSol.php?subId=91789f958cb1f8a472b9c2399989f3e1&pid=700553&user=mohitmcanitt
void helper(Node *root,vector<vector<int>>&ans,vector<int>v)
 {
     if(root==NULL)
        return;
     v.push_back(root->data);   
     if(root->left==NULL and root->right==NULL)
     {
         ans.push_back(v);
         return;
     }
     
     helper(root->left,ans,v);
     helper(root->right,ans,v);
 }
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>>ans;
    vector<int>v;
    helper(root,ans,v);
    return ans;
}
