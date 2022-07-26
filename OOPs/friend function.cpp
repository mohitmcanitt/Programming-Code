// friend function means accessing private
// data member of class to outside without 
// member function of that class.
// friend function is non member of class
// 

#include <iostream>
using namespace std;

class B;

class A{
    int a;
    friend void big(A,B);
    public:
    void set_A(int x)
    {
        a=x;
    }
};

class B{
    int b;
    friend void big(A,B);
    public:
    void set_B(int x)
    {
        b=x;
    }
};

void big(A obj1,B obj2)
{
    if(obj1.a>obj2.b)  
        cout<<"A is big than B";
    else if(obj1.a<obj2.b)
        cout<<"B is big than A";
    else
        cout<<"A is equal to B";        
}

int main() {
    A a1;
    a1.set_A(10);
    B b1;
    b1.set_B(20);
    big(a1,b1);
}
