
// 2->2->4->5
// 2->4->5
// 2->2->2->2
// 2

// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#

Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* t1=head;
    Node* t2=head;
    
    while(t1 and t2)
    {
        if(t1->data==t2->data)
            t2=t2->next;
        else
        {
            t1->next=t2;
            t1=t2; 
        }
    }
    t1->next=NULL;
    return head;
}
