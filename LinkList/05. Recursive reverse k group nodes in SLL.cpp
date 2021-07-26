// first reverse k nodes
// if still nodes to reverse(nxt_ptr!=NULL)
//   head->next=reverse(prev,k)
// return prev;  
  

node *recursive_kSize(node *head,int k)
{
    if(head==NULL)
        return head;
    node* current=head;
    node* prev=NULL;
    node* nxt_ptr;
    int count=1;
    while(count<=k and current) // first reverse starting k nodes
    {
        nxt_ptr=current->next;
        current->next=prev;
        prev=current;
        current=nxt_ptr;
        count++;
    }
    if(nxt_ptr)  // if still nodes to reverse if nxt_ptr!=NULL
        head->next=recursive_kSize(nxt_ptr,k);

    return prev;
}
