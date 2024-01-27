#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

void create_list(node *head, int val)
{
    node *temp = new node(val);
    if (head == nullptr)
        head = temp;
    else
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = temp;
    }
}

void display_node(node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout<<endl;
}

node* reverse_iterative(node* head){
    node* prev = NULL;
    node* current = head;
    node* next_y;

    while(head != nullptr || head->next != nullptr){
        next_node = head->next->next;
        head->next=temp;
        temp = head;
        head = next_node;
    }
    return head;
}


int main()
{
    node *head = new node(10);
    create_list(head, 20);
    create_list(head, 30);
    create_list(head, 40);

    display_node(head);
    head=reverse_iterative(head);
    display_node(head);
}