bool isValidBST(node *root,int minV=INT_MIN,int maxV=INT_MAX)
{
    if(root==NULL)
    reutrn true;

    if(root->data>minV and root->data<maxV and isValidBST(root->left,minV,root->data) and isValidBST(root->right,root->data,maxV))
    return true;
    return false;
}
