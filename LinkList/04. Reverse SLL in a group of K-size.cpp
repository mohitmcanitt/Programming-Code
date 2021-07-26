struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *temp=head;
        node *tail=NULL;
        node *new_head=NULL;
        
        while(temp)
        {
            node *current=temp;
            node *prev=NULL;
            node *nxt_ptr;
            int i=1;
            while(i<=k and current)
            {
                nxt_ptr=current->next;
                current->next=prev;
                prev=current;
                current=nxt_ptr;
                i++;
            }
            if(new_head==NULL)
                new_head=prev;
            if(tail!=NULL)
                tail->next=prev;
            tail=temp;
            temp=nxt_ptr;
        }
        return new_head;
    }
