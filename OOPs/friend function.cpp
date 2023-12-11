// friend function means accessing private
// data member of class to outside without 
// member function of that class.
// friend function is non member of class
// 

#include <iostream>
using namespace std;

class A{
    int a;
    friend void display();
    public:
    A(int a){
        this->a=a;
    }
};

void display(A obj){
    cout<<obj.a;
}

int main() {
    A obj(10);
    display(obj)
}


