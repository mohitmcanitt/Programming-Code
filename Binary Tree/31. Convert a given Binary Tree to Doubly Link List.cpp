// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
class DLL{
    public:
    Node* head;
    Node* tail;
};

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    DLL helper(Node *root)
    {
        DLL l;
        if(root==NULL)
        {
            l.head=NULL;
            l.tail=NULL;
            return l;
        }
        else if(root->left==NULL and root->right==NULL)
        {
            l.head=root;
            l.tail=root;
        }
            
        else if(root->left!=NULL and root->right==NULL)
        {
            DLL leftDLL=helper(root->left);
            root->left=leftDLL.tail;
            leftDLL.tail->right=root;
            
            l.head=leftDLL.head;
            l.tail=root;
        }
        else if(root->left==NULL and root->right!=NULL)
        {
            DLL rightDLL=helper(root->right);
            root->right=rightDLL.head;
            rightDLL.head->left=root;
            
            l.head=root;
            l.tail=rightDLL.tail;
        }
        else
        {
            DLL leftDLL=helper(root->left);
            DLL rightDLL=helper(root->right);
            
            root->left=leftDLL.tail;
            leftDLL.tail->right=root;
            
            root->right=rightDLL.head;
            rightDLL.head->left=root;
            
            l.head=leftDLL.head;
            l.tail=rightDLL.tail;
        }
        return l;
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        DLL obj=helper(root);
        return obj.head;
    }
};
