#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
    void print()
    {
        cout << "print function\n";
    }

private:
    Singleton(){};
};

int main()
{
    Singleton singleton = Singleton::getInstance();
    // Singleton obj; it is not allowed as constructor is prvt;
    // cout<<"Address: "<<&singleton;
    cout << "Address: " << &obj;
    singleton.print();
}
