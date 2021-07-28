// https://leetcode.com/problems/intersection-of-two-linked-lists/    
int count(ListNode *head)
    {
        if(head==NULL)
            return 0;
        return 1+count(head->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=count(headA);
        int len2=count(headB);
        
        ListNode *temp1=len1>=len2?headA:headB;
        ListNode *temp2=len1<len2?headA:headB;
        int i=1;
        while(i<=abs(len1-len2))
        {
            temp1=temp1->next;
            i++;
        }
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;   
    }
