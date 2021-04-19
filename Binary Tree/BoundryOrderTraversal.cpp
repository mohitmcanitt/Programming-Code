void leftboundry(Node *root,vector<int>&ans)
{
    if(root==NULL)
        return;
       
    if(root->left)   
    {
        ans.push_back(root->data);
        leftboundry(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        leftboundry(root->right,ans);
    }
}

void rightBoundry(Node *root,vector<int>&ans)
{
    if(root==NULL)
        return;
    if(root->right)
    {
        rightBoundry(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        rightBoundry(root->left,ans);
        ans.push_back(root->data);
    }
}

void printLeaves(Node *root,vector<int>&ans)
{
    if(root==NULL)
     return;

  if(root->left==NULL and root->right==NULL)
  {
       ans.push_back(root->data);
      return ;
  }
    printLeaves(root->left,ans);     
    printLeaves(root->right,ans);
}




vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int>ans;
     ans.push_back(root->data);
     
     leftboundry(root->left,ans);
      
     printLeaves(root->left,ans);
      
     printLeaves(root->right,ans);
      
     rightBoundry(root->right,ans);
    
     return ans;
}
