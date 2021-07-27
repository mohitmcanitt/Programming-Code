// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head==NULL)
        return head;
     Node *t1=head;
     Node *t2=head->next;
     
     unordered_set<int>us;
     us.insert(t1->data);
     
     while(t1 and t2)
     {
         if(us.find(t2->data)==us.end()) // 
         {
             us.insert(t2->data);
             t1->next=t2;
             t1=t2;
             t2=t2->next;
         }
         else
            t2=t2->next;
     }
     t1->next=NULL;
     return head;
     
    }
