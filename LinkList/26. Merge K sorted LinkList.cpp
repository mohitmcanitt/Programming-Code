    Node *merge(Node *l1,Node *l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        if(l1->data>l2->data)
            swap(l1,l2);
        Node *res=l1;
        
        while(l1 and l2)
        {
            Node *temp=NULL;
            while(l1 and l1->data<=l2->data)
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);    
        }
        return res;
            
    }
  
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           for(int i=K-2;i>=0;i--)
               arr[i]=merge(arr[i],arr[i+1]);
            return arr[0];
    }
