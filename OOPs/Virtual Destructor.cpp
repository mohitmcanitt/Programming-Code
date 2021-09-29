#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Base Constructor\n"; //1
    }
    virtual ~A()
    {
        cout<<"Base Destructor\n"; //4
    }
};
class B:public A
{
    public:
    B()
    { 
        cout<<"Derived Constructor\n"; //2
    }
    ~B()
    {
        cout<<"Derived Destructor\n"; //3
    }
};


int  main()
{
    A *obj=new B;
    delete obj;

}
