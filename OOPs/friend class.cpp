// friend class means accessing private
// data member of class to another class.
// Here class A data member is name
// which can be acceseed in class B

#include <iostream>
using namespace std;

class A{
    string name;;
    friend class B;
    public:
    void set_data(string new_name)
    {
        name=new_name;
    }
};

class B{
    public:
    void print_name(A &a)
    {
        cout<<a.name<<endl;
    }
};

int main() {
    A obj1;
    obj1.set_data("Rohit");
    B obj2;
    obj2.print_name(obj1);
}
