  bool findkey(Node *root,int key,vector<Node*>&ans)
    {
        if(root==NULL)
            return false;
        if(root->data==key)
        {
            ans.push_back(root);
            return true;
        }
        bool filc=findkey(root->left,key,ans);
        if(filc)
        {
            ans.push_back(root);
            return true;
        }    
        bool firc=findkey(root->right,key,ans);
        if(firc)
        {
            ans.push_back(root);
            return true;
        }
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
            vector<Node*>aPath;
            vector<Node*>bPath;
            
            findkey(root,n1,aPath);
            findkey(root,n2,bPath);
            
            int i=aPath.size()-1,j=bPath.size()-1;
            
            Node *temp=NULL;
            
            while(i>=0 and j>=0 and aPath[i]==bPath[j])
            {
                temp=aPath[aPath.size()-1];
                aPath.pop_back();
                bPath.pop_back();
                
                i--;
                j--;
            }
            return temp;
    }
