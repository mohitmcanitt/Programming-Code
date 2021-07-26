Node* reverseDLL(Node * head)
{
    Node* current=head;
    Node* nxt_ptr;
    Node* prev=NULL;
    while(current)
    {
        prev=current;
        nxt_ptr=current->next;
        swap(current->prev,current->next);
        current=nxt_ptr;
    }
    return prev;
}
