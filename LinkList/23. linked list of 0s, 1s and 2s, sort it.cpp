    Node* segregate(Node *head) {
        
        // Add code here
        Node *zero=new Node(-1);
        Node *pz=zero;
        
        Node *one=new Node(-1);
        Node *po=one;
        
        Node *two=new Node(-1);
        Node *pt=two;
        
        Node *current=head;
        Node *frwd;
        while(current)
        {
            frwd=current->next;
            if(current->data==0)
            {
                pz->next=current;
                pz=current;
            }
            else if(current->data==1)
            {
                po->next=current;
                po=current;
            }
            else
            {
                pt->next=current;
                pt=current;
            }
             if(frwd and current->data!=frwd->data)
                    current->next=NULL;
            current=frwd;     
        }
        if(zero->next) // starting with zero
        {
            if(one->next and two->next) //0 1 2
            {
                pz->next=one->next;
                po->next=two->next;
                two->next=NULL;
            }
            else if(one->next) // 0 1
            {
                pz->next=one->next;
                po->next=NULL; 
            }
            else if(two->next) // 0 2
            {
                pz->next=two->next;
                pt->next=NULL;
            }
            else // 0
            {
                pz->next=NULL;
            }
            return zero->next;
        }
        else if(one->next)
        {
            if(two->next)  // 1 2
            {
                po->next=two->next;
                pt->next=NULL;
            }
            else
                po->next=NULL;
            return one->next;    
        }
        else
            pz->next=NULL;
            return two->next;
       
    }

/*
Substitute of line 36-75
  zero->next = (oneD->next)? (oneD->next) : (twoD->next);
	one->next = twoD->next;
	two->next = NULL;

	// Updated head
	head = zeroD->next;

	// Delete dummy nodes
	delete zeroD;
	delete oneD;
	delete twoD;

	return head;

*/
