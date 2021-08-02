bool find(Node *root,int key,vector<Node*>&ans)
{
    if(root==NULL)
        return false;
    
    if(root->data==key)
    {
        ans.push_back(root);
        return true;
    }
    else if(root->data>key)
    {
        bool ls=find(root->left,key,ans);
        if(ls)
            ans.push_back(root);
        return ls;    
    }
    else
     {
        bool rs=find(root->right,key,ans);
        if(rs)
            ans.push_back(root);
        return rs;    
    }
}
