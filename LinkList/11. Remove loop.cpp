// Method 1: O(n) O(n)

void removeLoop(Node* head)
    {
        unordered_set<Node*>um;
        Node *temp=head;
        while(temp)
        {
            if(um.find(temp->next)!=um.end())
            {
                temp->next=NULL;
                return;
            }
            um.insert(temp);
            temp=temp->next;
        }
    }

// Method 2: O(n) and O(1)

Node* detectLoop(Node* head)
    {
        // your code here
        Node *slow=head;
        Node *fast=head;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return slow;
        }
        return NULL;
        
    }
    // start from here
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *temp1=head;
        Node *temp2=detectLoop(head);
        if(temp2==NULL) // loop doesn't exist
            return;
        
        if(temp2==temp1) // loop detected at first node
        {
            while(temp2->next!=temp1)
                temp2=temp2->next;
        }    
        else
        {
            while(temp1->next!=temp2->next)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        temp2->next=NULL;
    }
