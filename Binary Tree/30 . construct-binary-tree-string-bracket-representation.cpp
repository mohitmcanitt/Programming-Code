// https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int childFinder(string s,int si,int ei)
{
    stack<char>st;
    for(int i=si;i<=ei;i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            st.pop();
            if(st.empty())
                return i;
        }    
    }
    return -1;
}

node* buildTree(string s,int si,int ei)
{
    if(si>ei)
        return NULL;
    node* root=new node(s[si]);
    
    int index=-1;
    if(si+1<=ei and s[si+1]=='(')
        index=childFinder(s,si+1,ei);
    if(index!=-1)
    {
        root->left=buildTree(s,si+2,index-1);
        root->right=buildTree(s,index+2,ei-1);
    }
    return root;
}
void print(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);    
}

int main() 
{
    string s = "4(2(3)(1))(6(5))";
    node *root=buildTree(s,0,s.length()-1);
    print(root);
}
