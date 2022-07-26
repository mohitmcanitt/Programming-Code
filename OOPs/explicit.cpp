/*
  We use explicit specifier for constructor to specify 
  that the constructor would only be invoked explicitly 
  using parentheses () and curly braces {}. 
  The compiler will raise errors if the user tries to invoke 
  an explicit constructor using an assignment operator =
*/

#include<iostream>
using namespace std;

class A{
    string name_;
    public:
    explicit A(string name)
    {
        name_=name;
    }

    void print()
    {
        cout<<name_<<endl;
    }
};

int main()
{
    A obj={"Mohit"}; // give error.. 
                     // Assignment operator doesn't work with explicit
                     // If we remove explicit keyword , it will work.
    obj.print();
}
