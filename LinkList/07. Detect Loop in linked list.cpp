// Time : O(n2)
// Using two loops

// Time : o(n) 
// Space : 0(1)

bool detectLoop(Node* head)
    {
        // your code here
        unordered_set<Node*>us;
        Node *temp=head;
        while(temp)
        {
            if(us.find(temp)!=us.end())
                return true;
            us.insert(temp);
            temp=temp->next;
        }
        
        return false;     
    }

// Time : O(n)
// Space: O(1)

bool detectLoop(Node* head)
    {
        // your code here
        Node *slow=head;
        Node *fast=head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
        
    }
