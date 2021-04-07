/*
Number of pairs in an array with the sum greater than 0

Input : -4, 4, -5, 5, 3, -2, -3, -1, 2, 1
Output : 0

Approach:
step 1: we will use two pointer technique
step 2: Sort the given vector
step 3: For each value of i , we will take lower_bound from one 
        position ahead of it till last.
    int idx=lower_bound(begin(v)+i+1,end(v));

step 4: if idx is greater than equal to v.length(), means there is no value
           greater or equal to -v[i]+1;
       else
            increment ans by (size-idx) , bcoz from above idx a value be 
            potential candidate. 
step 5: repeat step 3-4 untill i<n-1;




*/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>v)
{
    int ans=0;
    sort(begin(v),end(v));
    for(int i=0;i<v.size()-1;i++)
    {
        int idx=lower_bound(begin(v)+i+1,end(v),-v[i]+1)-v.begin();
        if(idx<v.size())
            ans+=(v.size()-idx);
    }
    return ans;
}

int main() {
    vector<int>v={-4, 4, -5, 5, 3, -2, -3, -1, 2, 1};
    cout<<"Number of pairs "<<solve(v);
}
