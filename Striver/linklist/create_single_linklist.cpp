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

void create_list(node *root, int val)
{
    node *temp = new node(val);
    if (root == nullptr)
        root = temp;
    else
    {
        while (root->next != nullptr)
        {
            root = root->next;
        }
        root->next = temp;
    }
}

void display_node(node *root)
{
    while (root != nullptr)
    {
        cout << root->val << " ";
        root = root->next;
    }
}

int main()
{
    node *root = new node(10);
    create_list(root, 20);
    create_list(root, 30);
    create_list(root, 40);

    display_node(root);
}
