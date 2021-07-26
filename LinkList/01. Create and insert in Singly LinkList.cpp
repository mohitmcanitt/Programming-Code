#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

node *insert(node *head,int val)
{
    node *new_node=new node(val);
    if(head==NULL)
        head=new_node;
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new_node;    
    }    
    return head;
}

void printLL(node *head)
{
    node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    node *head=insert(NULL,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    printLL(head);
}
// Output: 10 20 30 40 50
