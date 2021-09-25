#include <iostream>
using namespace std;

class A
{
    int *arr;
    int size;
    public:
    A(int x)
    {
       this->size=x;
       arr=new int(size);
    }
    A(A &p)
    {
        arr=p.arr;  // this is shallow copy . It will just point to same heap section of previous object
        //arr=new int(p.size);  // this deep copy
        size=p.size;
    }

    void addElement(int x)
    {
        arr[0]=x;
    }
  void print()
  {
      cout<<arr[0]<<" "<<size<<endl;
  }
};

int main() {
    A obj1(10);
    A obj3(obj1);
    obj1.addElement(1000);
    obj1.print();
    obj3.print();
}
