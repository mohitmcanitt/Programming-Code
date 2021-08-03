// https://www.youtube.com/watch?v=6nJ_fUcCTNU
class var{
    public:
    bool isBST;
    int size;
    int min;
    int max;
};

var helper(Node* root)
{
    var v;
    if(root==NULL)
    {
        v.isBST=true;
        v.size=0;
        v.min=INT_MAX;
        v.max=INT_MIN;
        return v;
    }
    if(root->left==NULL and root->right==NULL)
    {
        v.isBST=true;
        v.size=1;
        v.min=root->data;
        v.max=root->data;
        return v;
    }
    var ls=helper(root->left);
    var rs=helper(root->right);

    if(ls.isBST and rs.isBST and root->data>ls.max and root->data<rs.min)
    {
        v.isBST=true;
        v.size=ls.size+rs.size+1;
        if(ls.min==INT_MAX)
            ls.min=root->data;
        if(rs.max==INT_MIN)
            rs.max=root->data;   
        v.min=ls.min;
        v.max=rs.max;
        return v;
    }
    else
    {
        v.isBST=false;
        v.size=max(ls.size,rs.size);
        v.min=0;
        v.max=0;
        return v;
    }
    

}


int largestBst(Node *root)
{
	//Your code here
	var ans=helper(root);
	return ans.size;
}
