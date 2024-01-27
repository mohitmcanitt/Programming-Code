#include<iostream>
using namespace std;

class complex{
    int real,img;
    public:
    complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    complex(){}

    complex operator + (complex b){
        complex a;
        a.real = real+b.real;
        a.img = img + b.img;
        return a;
    }
    void show(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};

int main(){
    complex c1(10,20);
    complex c2(5,5);
    complex c3 = c1 + c2;
    complex c4 = c1.operator+(c2);
    c4.show();

}