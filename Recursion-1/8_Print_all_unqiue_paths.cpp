#include <iostream>
#include <vector>
using namespace std;

vector<string> solve(int row, int col) {
    if (row < 0 || col < 0)
        return {};
    if (row == 0 && col == 0)
        return {""};

    vector<string> paths;

    vector<string> leftPaths = solve(row, col - 1);
    for (const auto& path : leftPaths) {
        paths.push_back(path + "R"); // Moving right in original path
    }

    vector<string> upPaths = solve(row - 1, col);
    for (const auto& path : upPaths) {
        paths.push_back(path + "D"); // Moving down in original path
    }

    return paths;
}

int main() {
    int m = 3; // rows
    int n = 2; // cols

    vector<string> paths = solve(m - 1, n - 1);

    for (const auto& path : paths)
        cout << path << " ";
}
