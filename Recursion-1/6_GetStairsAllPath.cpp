#include <iostream>
#include <vector>
using namespace std;

vector<string> getStairPaths(int n) {
    if (n == 0) return {""};
    if (n < 0) return {};

    vector<string> pathsFrom1Step = getStairPaths(n - 1);
    vector<string> pathsFrom2Steps = getStairPaths(n - 2);
    vector<string> pathsFrom3Steps = getStairPaths(n - 3);

    vector<string> allPaths;

    for (const auto& path : pathsFrom1Step) {
        allPaths.push_back("1" + path);
    }
    for (const auto& path : pathsFrom2Steps) {
        allPaths.push_back("2" + path);
    }
    for (const auto& path : pathsFrom3Steps) {
        allPaths.push_back("3" + path);
    }

    return allPaths;
}

int main() {
    int n = 3;
    vector<string> stairPaths = getStairPaths(n);
    for (const auto& path : stairPaths) {
        cout << path << endl;
    }
}
