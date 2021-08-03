// Dono tree ka inorder different array mai store kro
// Merge kro both tree ko
// Now create a new balanced BST

// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0
void inorder(TreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

TreeNode<int>* balancedBST(vector<int>&v,int s,int e)
{
    if(s>e)
        return NULL;
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left=balancedBST(v,s,mid-1);
    root->right=balancedBST(v,mid+1,e);
    
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    
    
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    vector<int>a;
    inorder(root1,a);
    inorder(root2,a);
    
    sort(begin(a),end(a));
    
    TreeNode<int> *root=balancedBST(a,0,a.size()-1);
    return root;
}
