#include <iostream>
using namespace std;

class A
{
    int l;
    int b;   

    public:
    void getData(int x,int y)
    {
        l=x;
        b=y;
    }
    void area()
    {
        cout<<"Area : "<<l*b;
    }

    A operator +(A obj) //operator overloading
    {
        A ans;
        ans.l=l+obj.l;
        ans.b=b+obj.b;
        return ans;
    }
};
int main() {
    A obj1;
    obj1.getData(10,10);
    A obj2;
    obj2.getData(20,20);

    A obj=obj1+obj2;   //obj1.operator+(obj2);
    obj.area();
}
