// I/P : 9->9
// O/P : 1->0->0

// Approach : O(N) O(1) 
// reverse given linklist
// Add 1 to it
// and again reverse
           

Approach 2: Using Recursion

    int helper(Node *temp)
    {
        if(temp==NULL)
            return 1;  // Add 2 to last digit
        int carry=helper(temp->next);
        int val=carry+temp->data;
        temp->data=val%10;
        return val/10;
    }
    
    Node* addOne(Node *head) 
    {
        int carry=helper(head);
        if(carry)
        {
            Node *new_node=new Node(carry);
            new_node->next=head;
            return new_node;
        }
        else
            return head;
    }
