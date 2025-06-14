void moveZeroes(struct Node*& head) {
        // code here
        Node* nonZeroHead=nullptr;
        Node* nonZeroTail=nullptr;
        Node* zeroHead=nullptr;
        Node* zeroTail=nullptr;
        
        Node* temp = head;
        while(temp){
            if(temp->data == 0){
                if(zeroHead==nullptr){
                    zeroHead=temp;
                    zeroTail=temp;
                }else{
                    zeroTail->next=temp;
                    zeroTail = temp;
                }
            }else{
                if(nonZeroHead==nullptr){
                    nonZeroHead = temp;
                    nonZeroTail = temp;
                }else{
                    nonZeroTail->next = temp;
                    nonZeroTail = temp;
                }
            }
            temp = temp->next;
        }
        if(zeroTail)
        zeroTail->next = nonZeroHead;
        if(nonZeroTail)
        nonZeroTail->next = nullptr;
        if(zeroHead)
        head = zeroHead;
    }
