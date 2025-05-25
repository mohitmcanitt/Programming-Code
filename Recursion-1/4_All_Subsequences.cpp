/*
                    ""                      <- Start with empty string
                  /    \
               "a"      ""                 <- Include 'a' / Exclude 'a'
              /   \     /   \
           "ab"  "a"  "b"    ""           <- Include/Exclude 'b'
          /  \   / \   / \   / \
       "abc""ab""ac""a""bc""b""c"" <- Include/Exclude 'c'

  */


#include <bits/stdc++.h>
using namespace std;

void generateSubsequence(string s, int index, string current,
                       vector<string>& subsequences) {
    if (index == s.length()) {
        subsequences.push_back(current);
        return;
    }
    generateSubsequence(s, index + 1, current + s[index], subsequences);
    generateSubsequence(s, index + 1, current, subsequences);
}

int main() {
    vector<string> subsequences;
    generateSubsequence("abc", 0, "", subsequences);
    for(const auto &str:subsequences)
        cout<<str<<endl;
}
