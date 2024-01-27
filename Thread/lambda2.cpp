#include <iostream>
#include <vector>
// lambda struct :-> [capture/variable] {param} (body)
// https://www.youtube.com/watch?v=R1bwTAarnz4&ab_channel=MikeShah
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    int sum = 0;
    /* Can't assign to sum variable as it need pass_by reference or mutable pass_by_copy
    auto sum_v = [sum] (int x) {sum+=x;};
   */

    auto sum_v = [sum] (int x) mutable {sum+=x;};
    for_each(v.begin(),
             v.end(),
              sum_v);
              
    std::cout<<sum; // Value won't get modified. But in case of global, it will 
}