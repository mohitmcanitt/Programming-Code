// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1# 
Node *middle(Node * head)
    {
        Node *slow=head;
        Node *fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node *reverse(Node *head)
    {
        if(head->next==NULL)
            return head;
        Node *new_head=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_head;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL or head->next==NULL)
            return true;
        Node *mid=middle(head);
        Node *l1=head;
        Node *l2=mid->next;
        mid->next=NULL;
        l2=reverse(l2);
        
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->data!=l2->data)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
        
        
    }
