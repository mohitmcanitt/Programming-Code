#include<iostream>

namespace A
{
    void print(std::string name)
    {
        std::cout<<"Class A : "<<name<<std::endl;
    }
}

namespace B
{
    void print(std::string name)
    {
        std::cout<<"Class B : "<<name<<std::endl;
    }
}
int main()
{
  B::print("MohitI");
}
