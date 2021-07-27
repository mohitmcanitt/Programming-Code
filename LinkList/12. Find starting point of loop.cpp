// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/    

ListNode *detectloop(ListNode* head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return slow;
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *temp=detectloop(head);
        if(temp==NULL)
            return NULL;
        ListNode *p1=head;
        ListNode *p2=temp;
        while(true)
        {
            if(p1==p2)
                return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;  
    }
