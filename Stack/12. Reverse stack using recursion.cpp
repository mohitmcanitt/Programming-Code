// Watch aditya verma video
#include<bits/stdc++.h>
using namespace std;

void helper(stack<int>&s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }
    int popped=s.top();
    s.pop();
    helper(s,temp);
    s.push(popped);    
}

void reverse(stack<int>&s)
{
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    reverse(s);
    helper(s,temp);    
}

int main() {
   stack<int>s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   cout<<s.top();
   reverse(s);
   cout<<s.top();
}
