// https://www.youtube.com/watch?v=DfIoVCQ2Lvg  
void solve(Node *root,int &count,int &ans,int K)
    {
        if(root==NULL)
            return;
        solve(root->left,count,ans,K);
        if(count==K)
        {
            ans=root->data;
            count++;
            return;
        }
        else
            count++;
        solve(root->right,count,ans,K);    
    }
    
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        int count=1;
        int ans=-1;
        solve(root,count,ans,K);
        return ans;
    }
