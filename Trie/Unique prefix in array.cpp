
/* 
smallest common prefix using trie
if no common prefix then return -1
Input

zebra
dog
dovedov
duck

Output:
z
dog
du
dove
-1

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    bool terminal;
    map<char,pair<Node*,int>>children;
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
    void insertValue(string s)
    {
        Node *temp=root;
        for(int i=0;i<s.length();i++)
        {
            if(temp->children[s[i]].first==NULL)
                {
                    Node *new_node=new Node(s[i]);
                    temp->children[s[i]].first=new_node;
                    temp->children[s[i]].second=1;
                }
             else
                 temp->children[s[i]].second+=1;
            temp=temp->children[s[i]].first;
        }
        temp->terminal=true;
    }
    string uniquePrefix(string s)
    {
        Node *temp=root;
        string ans="";
        int i;
        for(i=0;i<s.length();i++)
        {
            if(temp->children[s[i]].second==1)
             {
                ans+=s[i];
                break;
             }
            else
                ans+=s[i];
             temp=temp->children[s[i]].first;
        }
        if(i==s.length())
            return "-1";
        else
           return ans;
    }

};


int main() {
    Trie obj;
    vector<string>v={"zebra", "dog", "duck", "dove","dov"};
    for(int i=0;i<v.size();i++)
        obj.insertValue(v[i]);
    for(int i=0;i<v.size();i++)
        cout<<obj.uniquePrefix(v[i])<<endl;
}
