#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at end
    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    // Print list
    void print() const {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        ListNode* temp = head;
        while (temp) {
            ListNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    list.append(5);
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.print();
    return 0;
}
