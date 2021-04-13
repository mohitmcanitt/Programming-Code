/* 
Trie data structure

Phone Book Directory Implementation

Functionalities:

1. Add contacts
2. Delete contact
3. Print all contacts of Phone Book
4. Print all contacts matching with prefix word// Auto complete feature
5. Count Number of contacts in PhoneBook Directory


For documentation:
https://krishankantsinghal.medium.com/how-to-implement-phonebook-using-tries-data-structure-b19a83ac7f1e

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    bool terminal;
    map<char,Node*>children;
    Node(char ch)
    {
        data=ch;
        terminal=false;
    }
};

class Trie{
    Node *root;
    int total_count;
    public:
    Trie()
    {
        root=new Node('\0');
        total_count=0;
    }

    void addContacts(string name)
    {
        
         total_count++;
        Node *temp=root;
        for(int i=0;i<name.length();i++)
        {
            if(temp->children[name[i]]==0)
            {
                Node *new_node=new Node(name[i]);
                temp->children[name[i]]=new_node;
            }
            temp=temp->children[name[i]];
        }
        temp->terminal=true;          
    }
    
    void deleteContact(string name)
    {
        Node *temp=root;
        for(int i=0;i<name.length();i++)
        {
            if(temp->children[name[i]]==0)
            {
                cout<<name<<" do not exist in phone directory"<<endl<<endl;
                return;
            }
            temp=temp->children[name[i]];
        }
        if(temp->terminal==false)
         {
                cout<<name<<" exist.But as prefix of another contact name in phone directory. So cann't delete it"<<endl<<endl;
                return;
        }
        temp->terminal=false;
	      cout<<name<<" deleted successfully"<<endl<<endl;
    }
    
    // print all name from given node address temp
    void helper(string s,Node *temp)
    {   
        if(temp->terminal==true)
            cout<<s<<endl;
         for(auto x:temp->children)
             helper(s+x.first,x.second);
    }
    // Print contacts names
    void printContacts()
    {
        helper("",root);
        cout<<endl;
    }

    // Print contacts name whose name matches with prefix string
    void prefixPrint()
    {
        string prefix;
        cout<<"Enter a prefix string : ";
        cin>>prefix;
        Node *temp=root;
        for(int i=0;i<prefix.length();i++)
            {
                if(temp->children[prefix[i]]==0)
                    {
                        cout<<"No Results Found for "<<prefix<<endl;
                        return;
                    }
                    temp=temp->children[prefix[i]];
            }
            cout<<"Suggestions based on "<<prefix<<" are "<<endl;
            helper(prefix,temp);
    }
    // Get number of contacts saved in the contact
    void total_contact_numbers()
    {
         cout<<"Total number of contacts at present is "<<total_count<<endl<<endl;
    }
};



int main() {
    Trie obj;
    vector<string>default_contacts={"Customer Care","Emergency","Ambulance","Fire","Police","Balance Enquiry"};
    //Add default contacts in phone book directory
    for(auto x:default_contacts)
        obj.addContacts(x);
    int choice;
      while(true)
     {
        cout<<"Enter your choice : ";
        cout<<endl;
        cout<<"1. Add contacts"<<endl;
        cout<<"2. Delete existing Contacts"<<endl;
        cout<<"3. Print all contacts of Phone Book"<<endl;
        cout<<"4. Print all contacts matching with prefix word"<<endl;
        cout<<"5. Count Number of contacts in PhoneBook Directory"<<endl;
        cout<<"6. Exist from program"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter contact name to add in Phone Directory : ";
            string name;
            cin>>name;
            obj.addContacts(name);
        }
        else if(choice==2)
        {
            cout<<"Enter contact name to delete from phone directory : ";
            string str;
            cin>>str;
            obj.deleteContact(str);
        }  
        else if(choice==3)
            obj.printContacts();
        else if(choice==4)
            obj.printContacts();
        else if(choice==5)
            obj.printContacts();
         else
            break;
     }       
}
