
#include <bits/stdc++.h>
using namespace std;

class Person{
    
    public:
    int age;
    string name;
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};

class PersonCompare{
    public:
    bool operator()(Person a,Person b)
    {
        return a.age>b.age; // min
    }
};

int main() 
{
    priority_queue<Person,vector<Person>,PersonCompare> pq;
    int n;
    cin>>n;
    while(n--)
    {
        string name;
        int age;
        cin>>name>>age;
        Person p(name,age);
        pq.push(p);
    }    
    Person p=pq.top();
    cout<<p.name<<" "<<p.age<<endl;
}
/*
3
A 20
B 10
C 5
OUTPUT

C 5

*/
