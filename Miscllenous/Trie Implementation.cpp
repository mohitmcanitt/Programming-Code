/*
Each node will have 3 part

1. Data
2. Terminal means words end here
3. mapping on next 26 children.. unordeded_map<char,Node*>


*/


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*>children;
    char data;
    bool terminal;
    Node(char ch)
    {
        data=ch;
        terminal=false;
    }
};

class Trie{
    Node *root;
    public:
    Trie()
    {
        root=new Node('\0');
    }
    void insertWord(string s)
    {
       Node *temp=root;
        for(int i=0;i<s.length();i++)
        {
           if(temp->children[s[i]]==0)
           {
               Node *new_node=new Node(s[i]);
               temp->children[s[i]]=new_node;
           }
           temp=temp->children[s[i]];
        }
        temp->terminal=true;
    }
    bool find(string word)
    {
        Node *temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->children[word[i]]==0)
                return false;
              temp=temp->children[word[i]];
        }
        return temp->terminal;
    }
};

int main() {
   vector<string>words={"Apple","Ape","News","Not"};
   Trie obj;
   
   for(int i=0;i<words.size();i++)
        obj.insertWord(words[i]);
        
    if(obj.find("News"))
    cout<<"Present";
    else
    cout<<"Absent";
}
