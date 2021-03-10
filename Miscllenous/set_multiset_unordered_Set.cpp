#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>v={2,3,1,2,3,6,5,4,3};
    set<int>s(v.begin(),v.end());
    for(auto x:s)
    cout<<x<<" ";  // 1 2 3 4 5 6
    cout<<endl;
    multiset<int>ms(v.begin(),v.end());
    for(auto x:ms)
    cout<<x<<" ";  // 1 2 2 3 3 3 4 5 6
    cout<<endl;
    unordered_set<int>us(v.begin(),v.end());
    for(auto x:us)
    cout<<x<<" "; //4 5 6 1 3 2
}
