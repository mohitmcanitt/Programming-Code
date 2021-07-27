// Find Middle elements  
Node* middle(Node *temp)  
    {
        Node *slow=temp;
        Node *fast=temp;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
 // Merge two sorted link list   
    Node *merge(Node *l1,Node *l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        Node *temp;
        if(l1->data<l2->data)
        {
            temp=l1;
            temp->next=merge(l1->next,l2);
        }
        else
        {
            temp=l2;
            temp->next=merge(l1,l2->next);
        }
        return temp;
    }
    
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL or head->next==NULL)
            return head;
        
        Node *mid=middle(head); // divide linkList with mid into two parts 
        Node *head1=head;       // head1 will point out 1 lists
        Node *head2=mid->next;  // head2 will point out 2 lists
        mid->next=NULL;         // to disconnect list1 to list2
        head1=mergeSort(head1); // again call for sub problem as list1
        head2=mergeSort(head2); // again call for sub problem as list2
        // Above code will produce two sorted linklist
        return merge(head1,head2);  // merge two sorted linklist
        
    }
