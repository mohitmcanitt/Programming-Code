// Here we have created object of derived class and base class pointer is pointing to derived class object.
// When we try to call method(), base class methods gets called irrespective , it is holding reference of derived class object.
// So, when there is no any virtual function, then base function will get calls.
// It is compile time polymorphism, because functions gets decide at compile/build time.

#include<iostream>
using namespace std;

class A{
    public:
    void show(){
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

