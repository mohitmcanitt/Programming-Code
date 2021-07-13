// leetcode 198
// input 1 2 9 4 5 0 4 11 6
// output : 26(1,9,5,11)


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>v,bool include,int index,int ans)
{
    if(index==v.size())
        return ans;
    if(include)
        return max(solve(v,false,index+1,ans+v[index]),solve(v,true,index+1,ans));
    else
        return solve(v,true,index+1,ans);        
}

int main() {
    vector<int>v{1,2,9,4,5,0,4,11,6};
    cout<<solve(v,true,0,0);
}
