
#include<iostream>
using namespace std;

class A{
    public:
    virtual void show(){
        cout<<"Class A";
    }
};

class B:public A{
    public:
    void show(){
        cout<<"class B";
    }
};

int main(){
    B b;
    A *obj;
    obj = &b;
    obj->show();
}

/*
https://www.geeksforgeeks.org/cpp-polymorphism/

A virtual function is a member function that is declared within a base class and 
is re-defined (overridden) by a derived class.
When you refer to a derived class object using a pointer or a reference to the base class, 
you can call a virtual function for that object and execute the derived class’s version of the method.

Virtual functions ensure that the correct function is called for an object, 
regardless of the type of reference (or pointer) used for the function call.

It is used to achieve runtime polymorphism.

*/
