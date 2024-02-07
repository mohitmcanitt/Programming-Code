#include <iostream>

template <typename T1>
/*
template<typename T2>
At a time only one template declaration is allowed and it should be immediate next line.
*/

T1 square(T1 input)
{
    return input * input;
}

template <typename T2>
T2 cube(T2 input)
{
    return input * input * input;
}
/*
T2 sum(T2 input1,T2 input2){
    return input1+input2;
}
Compile time error. One template is allowed to one function name only.
*/

int main()
{
    std::cout << square(5) << std::endl;
    std::cout << cube(5) << std::endl;

    std::cout << square<int>(6.5f); // 36
    // Here we are explicitly telling compiler to use integer version of template
    // It will give warning. Use -w flag to
}