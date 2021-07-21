// Watch Aditya verma video

#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&st,int temp)
{
    if(st.size()==0 or st.top()>=temp)
    {
        st.push(temp);
        return;
    }
    int y=st.top();
    st.pop();
    insert(st,temp);
    st.push(y);
    return;
}

void sort(stack<int>&st)
{
    if(st.size()==1)
        return;
    int temp=st.top();
    st.pop();
    sort(st);
    insert(st,temp);
    return;    
}

int main() {
    stack<int>st;
    st.push(5);
    st.push(1);
    st.push(10);
    st.push(2);

    sort(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }    

}
