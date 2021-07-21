#include<bits/stdc++.h>
using namespace std;

//  6 8 0 1 3
//  8-1 1 3 -1

//  8

void nextGreaterRight(vector<int>&v)
{
    stack<int>st;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(st.empty())
        {
           st.push(v[i]);
           v[i]=-1; 
        }    
        else if(v[i]<st.top())
        {
            int temp=v[i];
            v[i]=st.top();
             st.push(temp);
             
        }
        else
        {
            while(!st.empty() and st.top()<=v[i])
                st.pop();
            if(st.empty())
            {
                st.push(v[i]);
                v[i]=-1;
            }
            else
            {
                int temp=v[i];
                v[i]=st.top();
                st.push(temp);
            }
        }
           
    }        
}

int main() {
    vector<int>v={6,8,0,1,3};
    nextGreaterRight(v);
    for(auto x:v)
        cout<<x<<" ";

}
