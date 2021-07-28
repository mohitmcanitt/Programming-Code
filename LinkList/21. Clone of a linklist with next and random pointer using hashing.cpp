// https://www.youtube.com/watch?v=deaZgauZVco watch from 10:00 minutes    
Node *copyList(Node *head)
    {
        //Write your code here
        unordered_map<Node*,Node*>um;
        Node *new_head=NULL,*tail=NULL;
        Node *temp=head;
        
        while(temp)
        {
            Node *new_node=new Node(temp->data);
            if(new_head==NULL)
            {
                new_head=new_node;
                tail=new_node;
            }
            else
            {
                tail->next=new_node;
                tail=new_node;
            }
            um[temp]=new_node;
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            um[temp]->arb=um[temp->arb];
            temp=temp->next;
        }
        return new_head;
    }
