// https://cplusplus.com/reference/memory/unique_ptr/release/
#include <iostream>
#include <memory>
using namespace std;

class A
{
    int a_;
    public:
    A(int a):a_(a){}
    void print()
    {
        std::cout<<a_<<std::endl;
    }
};

int main() {
    unique_ptr<A>u_ptr1(new A(10));
    
    unique_ptr<A>u_ptr2(u_ptr1.release());
    u_ptr1->print(); //error u_ptr1 will be NULL.
    u_ptr2->print(); 

    std::cout<<u_ptr2.get()<<std::endl;
}
