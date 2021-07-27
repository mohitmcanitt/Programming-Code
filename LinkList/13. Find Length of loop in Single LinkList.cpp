// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1#
Node *detect(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return slow;
    }
    return NULL;
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *meetingPoint=detect(head);
    if(meetingPoint==NULL)
        return 0;
    Node *temp=meetingPoint->next;        
    int count=1;
    while(temp!=meetingPoint)
    {
        count++;
        temp=temp->next;
    }
    return count;
    
}
