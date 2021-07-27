// Time : O(m+n)
// Space : O(m+n) recursive calls stack size

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* new_head;
        if(l1->val<l2->val)
        {
            new_head=l1;
            new_head->next=mergeTwoLists(l1->next,l2);
        } 
        else
        {
            new_head=l2;
            new_head->next=mergeTwoLists(l1,l2->next);
        }
        return new_head;
        
    }
// Time : O(m+n)
// Space : O(1) inplace just changing links
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        if(l1->val>l2->val)
            swap(l1,l2);
        
        ListNode *new_head=l1;
        while(l1!=NULL and l2!=NULL) 
        {
            ListNode* temp=NULL;
            while(l1!=NULL and l1->val<=l2->val )
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return new_head;
}  
