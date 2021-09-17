#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node *next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};


void *createLL(node *&head,char ch)
{
    node *new_node=new node(ch);
    if(head==NULL)
        head=new_node;
    else
    {
        node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;        
    }
    return NULL;
}

void printLL(node *temp)
{
    while(temp)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}

node *reverse(node *&head)
{
    if(head==NULL)
        return NULL;
    node *prev=NULL;
    node *temp=head;
    node *nxt_ptr;
    while(temp)
    {
        nxt_ptr=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt_ptr;
    }    
    return prev;
}

bool isPalindrone(node *root)
{
    node *slow=root;
    node *fast=root->next;

    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    node *mid=reverse(slow->next);
    slow->next=mid;
    
    node *temp1=root;
    node *temp2=mid;
    while(temp2)
    {
        if(temp1->data!=temp2->data)
            return false;
            temp1=temp1->next;
            temp2=temp2->next;
    }

    return true;

}

int main()
{
    node *head=NULL;
    createLL(head,'a');
    createLL(head,'b');
    createLL(head,'b');
    createLL(head,'a');

    //printLL(head);
    bool ans=isPalindrone(head);
    if(ans)
        cout<<"LinkList is Palindrone\n";
    else
    cout<<"LinkList is Not Palindrone\n";
}
