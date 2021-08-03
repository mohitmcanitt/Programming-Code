void solve(Node *root,int l,int h,int &ans)
{
   if(root==NULL)
    return;
   
   if(root->data>=l and root->data<=h) 
        ans+=1;
    
   solve(root->left,l,h,ans);
   solve(root->right,l,h,ans);
    
}
int getCount(Node *root, int l, int h)
{
  // your code goes here   
    int ans=0;
    
    solve(root,l,h,ans);
    return ans; 
 }
