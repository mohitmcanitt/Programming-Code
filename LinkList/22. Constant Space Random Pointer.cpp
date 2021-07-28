// Watch for concept : https://www.youtube.com/watch?v=IGWJg9wDaF0

 Node* copyRandomList(Node* head) {
        Node* current=head;
        
        while(current)
        {
            Node* forward=current->next;
            Node *new_node=new Node(current->val); // making newly node as middle node in b/t curr and forward
            current->next=new_node;
            new_node->next=forward;
            current=forward;
        }
        
        current=head;
        while(current)
        {
            Node *rand=current->random;
            if(rand)
                current->next->random=rand->next;
             current=current->next->next;    
        }
        
        Node *dummy=new Node(-1);
        Node *prev=dummy;
        current=head;
        while(current)
        {
            prev->next=current->next;
            current->next=current->next->next;
            prev=prev->next;
            current=current->next;
        }
        return dummy->next;
    }
