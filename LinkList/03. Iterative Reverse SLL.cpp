node *iterative_reverse(node *head)
{
    node *prev=NULL;
    node *current=head;
    node *nxt_ptr;

    while(current!=NULL)
    {
        nxt_ptr=current->next;
        current->next=prev;
        prev=current;
        current=nxt_ptr;
    }
    return prev;
}
