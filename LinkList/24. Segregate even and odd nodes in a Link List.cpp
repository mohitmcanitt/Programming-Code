 Node* divide(int N, Node *head){
        // code here
        Node *even=new Node(-1);
        Node *evenPtr=even;
        
        Node *odd=new Node(-1);
        Node *oddPtr=odd;
        
        Node *current=head;
        Node *frwd;
        
        while(current)
        {
            frwd=current->next;
            if(current->data%2==0)
            {
                evenPtr->next=current;
                evenPtr=current;
            }
            else
            {
                oddPtr->next=current;
                oddPtr=current;
            }
            if(frwd and ((current->data%2==0) ^ (frwd->data%2==0)))
                current->next=NULL;
            current=frwd;
        }
        
        evenPtr->next=odd->next;
        oddPtr->next=NULL;
        return even->next;
    }
