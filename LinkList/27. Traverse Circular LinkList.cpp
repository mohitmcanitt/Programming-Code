void printCLL(node *head)
{
    node *temp=head;
    if(temp==NULL)
        return;
   do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
}
