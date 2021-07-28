// Watch : prepcoding https://www.youtube.com/watch?v=tK4eez3syAQ
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node *insert(Node* head,int val)
{
    Node* new_node=new Node(val);
    if(head==NULL)
        head=new_node;
    else
    {
        Node* temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;    
    }    
    return head;
}
Node *ans;
void addFront(int val)
{
    Node *new_node=new Node(val);
    new_node->next=ans;
    ans=new_node;
}

int count(Node *head)
{
    if(head==NULL)
        return 0;
    return 1+count(head->next);    
}

int helper(Node *head1,int pos1,Node *head2,int pos2)
{
    if(head1==NULL and head2==NULL)
        return 0;
    int data=0;    
    if(pos1>pos2)
    {
        int carry=helper(head1->next,pos1-1,head2,pos2);
        data=head1->data+carry;
    }
        
    else if(pos1<pos2)
    {
        int carry=helper(head1,pos1,head2->next,pos2-1);       
        data=head2->data+carry;
    } 
    else   
    {
        int carry=helper(head1->next,pos1-1,head2->next,pos2-1);
        data=head1->data+head2->data+carry;
    } 
    addFront(data%10);
    return data/10;    
}

void addTwoSum(Node *head1,Node *head2)
{
    int l1=count(head1);
    int l2=count(head2);
   
    int carry=helper(head1,l1,head2,l2);
    if(carry)
        addFront(carry);
}
void printLL(Node* temp)
{
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
