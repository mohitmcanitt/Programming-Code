#include<iostream>
#include<vector>
// lambda struct :-> [capture/variable] {param} (body)

struct print_functor{
    void operator()(int x){
        std::cout<<x<<" ";
    }
};

int main(){
    std::vector<int> v{1,2,3,4,5};
    auto func = [] (int x) {std::cout<<x<<" ";};
    for_each(v.begin(),
             v.end(),
             [](int x){std::cout<<x<<" ";});
    std::cout<<"\n";
    for_each(v.begin(),
             v.end(),
             func);
    std::cout << "\n";
    for_each(v.begin(),
             v.end(),
             print_functor());
}