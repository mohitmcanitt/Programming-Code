// Approach 1: using reverse both linklist and extra space
struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *head1=reverse(first);
        Node *head2=reverse(second);
        Node *head=new Node(0); // dummy node
        Node *temp=head;
        int carry=0;
        int sum;
        while(head1 and head2)
        {
            sum=carry+head1->data+head2->data;
            Node *new_node=new Node(sum%10);
            temp->next=new_node;
            temp=new_node;
            carry=sum/10;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1)
        {
            sum=head1->data+carry;
            Node *new_node=new Node(sum%10);
            temp->next=new_node;
            temp=new_node;
            carry=sum/10;
            head1=head1->next;
        }
        while(head2)
        {
            sum=head2->data+carry;
            Node *new_node=new Node(sum%10);
            temp->next=new_node;
            temp=new_node;
            carry=sum/10;
            head2=head2->next;
        }
        if(carry)
        {
            Node *new_node=new Node(carry);
            temp->next=new_node;
        }
        
       temp=head->next;
       head->next=NULL;
      
        return reverse(temp);
    }
