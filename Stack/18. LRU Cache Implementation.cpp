/*
Input:

2
2
2
SET 1 2 GET 1
2
7
SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1

Output:
2 
5 -1 
*/

#include <bits/stdc++.h>
using namespace std;


struct Node{
    
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k,int v)
    {
        key = k;
        value = v;
        next = prev = NULL;
    }
};



class LRUCache
{
private:
    unordered_map<int,Node*> mymap;
    int capacity,count;
    Node* head;
    Node* tail;

public:
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
        count = 0;
    }
    
    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(Node* node)
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    int get(int key)
    {
        if(mymap.find(key) != mymap.end())
        {
            Node* temp = mymap[key];
            int result = temp->value;
            deleteNode(temp);
            addToHead(temp);
            return result;
        }
        
        return -1;

    }
    
    void set(int key, int value)
    {
        
        if(mymap.find(key) != mymap.end())
        {
            Node* temp = mymap[key];
            temp->value = value;
            deleteNode(temp);
            addToHead(temp);
        }
        else
        {
            Node* temp = new Node(key,value);
            mymap[key] = temp;
            
            if(count<capacity)
            {
                count++;
                addToHead(temp);
            }
            else
            {
                mymap.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(temp);
            }
        }
    }
};




int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
