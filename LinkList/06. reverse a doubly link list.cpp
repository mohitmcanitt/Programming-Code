Node* reverseDLL(Node * head)
{
    Node* current=head;
    Node* nxt_ptr;
    Node* head_of_reverse=NULL;
    while(current)
    {
        head_of_reverse=current;
        nxt_ptr=current->next;
        swap(current->prev,current->next);
        current=nxt_ptr;
    }
    return prev;
}
