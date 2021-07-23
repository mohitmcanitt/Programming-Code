/*
Input:
2
7
SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1

Output:
5 -1 
*/
// watch this for theory : https://www.youtube.com/watch?v=S6IfqDXWa10
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
        prev=NULL;
    }
};

class LRUcache{

    unordered_map<int,Node*>um;
    int capacity;
    int count;
    Node *head;
    Node *tail;

    public:
    LRUcache(int cap)
    {
        capacity=cap;
        count=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    
    void deleteNode(Node *root)
    {
        root->prev->next=root->next;
        root->next->prev=root->prev;
        delete root;
    }

    void addFront(Node *node)
    {
       node->next=head->next;
       node->next->prev=node;
       node->prev=head;
       head->next=node;

    }
    int get(int key)
    {
        if(um.find(key)!=um.end()) // If key is present, move it front 
        {
            Node * it=um[key];
            int result=it->value;
            deleteNode(it);
            Node *new_node=new Node(key,result);
            addFront(new_node);
            um[key]=new_node;
        
            return result;
        }
        else
            return -1;
    }
    void set(int key,int val)
    {
        if(um.find(key)!=um.end()) // If key is present, move it front 
        {
            auto it=um[key];
            deleteNode(it);
            Node *new_node=new Node(key,val);
            addFront(new_node);
            um[key]=new_node;
        }
        else 
        {
            if(count<capacity)
            {
                Node *new_node=new Node(key,val);
                um[key]=new_node;
                addFront(new_node);
                count++;
            }
            else
            {
                um.erase(tail->prev->key);
                deleteNode(tail->prev);
                Node *new_node=new Node(key,val);
                um[key]=new_node;
                addFront(new_node);
            }
        }
    }

};

int main() {
    int cap;
    cin>>cap;
    int query;
    cin>>query;
    LRUcache obj(cap);
    while(query--)
    {
        string s;
        cin>>s;
        if(s=="SET")
        {
            int key,val;
            cin>>key>>val;
            obj.set(key,val);
        }
        else
        {
            int key;
            cin>>key;
            cout<<obj.get(key)<<" ";
        }
    }
   


}
