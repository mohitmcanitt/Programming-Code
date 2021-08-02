// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#   
// First leaf node find kro uske level ko store kro
// Next time jab kabhi koi leaf node mile aur uska level==leafLevel then true else false;
    bool helper(Node *root,int level,int &leafLevel)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL and root->right==NULL)
        {
            if(leafLevel==0)
            {
                leafLevel=level;
                return true;
            }               
            else
                return leafLevel==level;
        }
        return helper(root->left,level+1,leafLevel) and helper(root->right,level+1,leafLevel);
    }
    
    bool check(Node *root)
    {
        //Your code here
        int level=0;
        int leafLevel=0;
        
        return helper(root,level,leafLevel);
    }
