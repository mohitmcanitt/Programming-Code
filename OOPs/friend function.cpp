// friend function means accessing private
// data member of class to outside without 
// member function of that class.
// friend function is non member of class
//

#include <iostream>
using namespace std;

class A
{
    int a_;
    friend void display(A);

public:
    A(int a) : a_(a){};
};

void display(A obj){
    cout<<obj.a_;
}

int main() {
    A obj(10);
    display(obj)
}


