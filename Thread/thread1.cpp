#include<iostream>
#include<thread>

void test(int x){
    std::cout<<"Hello from x: "<<x<<std::endl;
    std::cout<<"My name is mohit kumar" <<std::endl;
}

int main(){
    std::thread t1(&test,10);
    t1.join();
    std::cout<<"Mohit"<<std::endl;
}