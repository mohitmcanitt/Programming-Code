#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& vec, int n) {
    if (n == 1)
        return vec[0];
    return max(vec[n - 1], solve(vec, n - 1));
}

int main() {
    vector<int> vec{1, 22, 3, 44, 5};
    cout << solve(vec, vec.size());
}
