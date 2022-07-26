#include <iostream>
using namespace std;

class A{
    int a;
    public:
        class B{
            int b;
            public:
            B(int x):b(x){}
            void print_b()
            {
                cout<<"B: "<<b<<endl;
            }
        };
        class C{
            int c;
            public:
            C(int x):c(x){}
            void print_c()
            {
                cout<<"C: "<<c<<endl;
            }
        }; 
};

int main() {
    A::B obj_b(10);
    A::C obj_c(20);

    obj_b.print_b();
    obj_c.print_c();
}
// output
// B: 10
// C: 20
