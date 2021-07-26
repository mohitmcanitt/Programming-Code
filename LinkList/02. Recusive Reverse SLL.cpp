node *recursive_reverse(node *head)
{
    if(head==NULL or head->next==NULL)
        return head;
    node *new_head=recursive_reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;    
}
