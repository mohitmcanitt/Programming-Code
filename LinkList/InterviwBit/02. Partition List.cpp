/*
1. create two pointer less and greater_equal
2. less pointer will point to list containg value less than B
3. greater_equal will point to list containg value greater than equal to B
4. remaing same as sorting 0 and 1
*/

ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* less=new ListNode(-1);
    ListNode* g_equal=new ListNode(-1);

    ListNode* p1=less;
    ListNode* p2=g_equal;

    ListNode *l1=A;
    while(l1)
    {
        if(l1->val<B)
        {
            p1->next=l1;
            p1=l1;
        }           
        else
        {
            p2->next=l1;
            p2=l1;
        } 
        l1=l1->next;  
    }
    p1->next=g_equal->next;
    p2->next=NULL;
    return less->next;

}
