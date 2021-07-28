// Watch : prepcoding https://www.youtube.com/watch?v=tK4eez3syAQ

// A : [ 9 -> 9 -> 9 ]
// B : [ 1 ]

// O/P : 1->0->0->0
    
int count(ListNode *head)
{
    if(head==0)
        return 0;
    return 1+count(head->next);
}
void addFront(ListNode *&head,int val)
{
    ListNode* new_node=new ListNode(val);
    new_node->next=head;
    head=new_node;
}

int helper(ListNode *l1,int pos1,ListNode *l2,int pos2,ListNode *&head)
{
    if(l1==NULL and l2==NULL)
        return 0;
    int data=0;
    if(pos1>pos2)
    {
        int carry=helper(l1->next,pos1-1,l2,pos2,head);
        data=carry+l1->val;
    }    
    else if(pos1<pos2)
    {
        int carry=helper(l1,pos1,l2->next,pos2-1,head);
        data=carry+l2->val;
    }
    else
    {
        int carry=helper(l1->next,pos1-1,l2->next,pos2-1,head);
        data=carry+l1->val+l2->val;
    }
    int new_data=data%10;
    int new_carry=data/10;
    addFront(head,new_data);
    return new_carry;
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;

    int l1=count(A);
    int l2=count(B);
    ListNode *head=NULL;
    int carry=helper(A,l1,B,l2,head);  
    if(carry)
        addFront(head,carry);
    return head;     
}

int main() {
    Node* head1=insert(NULL,3);
    insert(head1,5);

    printLL(head1);

    Node* head2=insert(NULL,9);
    insert(head2,9);
    insert(head2,9);

    printLL(head2);

    addTwoSum(head1,head2);
    Node *temp=ans;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }  
}
