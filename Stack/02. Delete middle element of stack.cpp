#include<bits/stdc++.h>
using namespace std;

int solve(stack<int>&s,int k)
{
    if(k==1)
        return s.top();
    int temp=s.top();
    s.pop();
    return solve(s,k-1);
}

void deleteMiddle(stack<int>&s)
{
    int n=s.size();
    cout<<solve(s,n/2);

}

int main() {
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    cout<<endl;
    deleteMiddle(s);
    cout<<s.top();
}
