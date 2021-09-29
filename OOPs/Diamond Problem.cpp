#include<iostream>
using namespace std;

class A
{
    public:
    int a;
    void display()
    {
        cout<<"Class A";
    }
};

class B:virtual public A
{
    public:
    int b;
};

class C:virtual public A
{
    public:
    int c;
};

class D:public B,public C
{
    public:
    int d;
};

int main()
{
    D obj;
    cout<<sizeof(obj);
    obj.display();
    
}
