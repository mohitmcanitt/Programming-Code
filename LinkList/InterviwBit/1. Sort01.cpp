/*
 create two dummy node i.e. ones and zeroes
 zeros will point to linklist containging 0 only
 ones will point to linklist containing 1 only 
 
 create two different pointer pz(pointer to zero) and po(pointer to one) 
 It will help in itertating in their respective list
 
 now l1=head;
 iterate loop until l1 is NULL
 
 do following:
 1. store next node address
   a. if curr node value is 1
        po->next=l1;
        po=l1;
   b. if curr node value is 0
        pz->next=l1;
        pz=l1;
   At the end of loop 
   check if next element is not same as this node element 
   then l1->next=NULL;
    now update l1=l1->next;
  
  Now once loop is over 
  make pz->next=ones->next;
      po->next=NULL;
      
      return pz->next;


*/
ListNode* Solution::solve(ListNode* A) {
    ListNode* zeroes=new ListNode(-1);
    ListNode* pz=zeroes;

    ListNode* ones=new ListNode(-1);
    ListNode* po=ones;

    ListNode *l1=A;
    while(l1)
    {
        ListNode *nxt_node=l1->next;
        if(l1->val==0)
        {
            pz->next=l1;
            pz=l1;
        }
        else
        {
            po->next=l1;
            po=l1;
        }
        if(nxt_node and nxt_node->val!=l1->val)
            l1->next=NULL;
        l1=nxt_node;    
    }
    pz->next=ones->next;
    po->next=NULL;
    return zeroes->next;
}
