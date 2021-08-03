// Watch : https://www.youtube.com/watch?v=DfIoVCQ2Lvg
void solve(Node *root,int &ans,int &count,int K)
    {
        if(root==NULL)
            return;
        solve(root->right,ans,count,K);
        if(count==K)
        {
            ans=root->data;
            count++;
            return;
        }
        else
            count++;
        solve(root->left,ans,count,K);    
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans=-1;
        int count=1;
        solve(root,ans,count,K);
        return ans;
    }
