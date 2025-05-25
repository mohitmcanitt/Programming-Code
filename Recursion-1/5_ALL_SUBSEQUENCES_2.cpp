#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences of the input string
vector<string> generateSubsequences(const string& input) {
    if (input.empty()) return {""};

    char firstChar = input[0];                // e.g., 'a'
    string remaining = input.substr(1);       // e.g., "bc"

    vector<string> smallerResult = generateSubsequences(remaining);

    vector<string> result;
    for (const string& subseq : smallerResult) {
        result.push_back(subseq);             // Exclude firstChar
        result.push_back(firstChar + subseq); // Include firstChar
    }

    return result;
}

int main() {
    string input = "abc";
    vector<string> subsequences = generateSubsequences(input);

    for (const string& s : subsequences) {
        cout << "\"" << s << "\"" << endl;
    }

    return 0;
}
