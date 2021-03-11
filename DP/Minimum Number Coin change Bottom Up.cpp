// Minimum number coin change problem
// Bottom-Up approach

#include <bits/stdc++.h>
using namespace std;
// return all possible denomination which is <=amount
vector<int> helper(vector<int>v,int amount)  
{
    vector<int>ans;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=amount)
        ans.push_back(v[i]);
    }
    return ans;
}

int solve(vector<int>coins,int amount)
{
    int dp[amount+1];
    dp[0]=0;
    for(int i=1;i<=amount;i++)
    {
        int minCoinRequired=INT_MAX;
        vector<int>allowedDenomination=helper(coins,i);
        for(auto x:allowedDenomination)
        {
            minCoinRequired=min(minCoinRequired,dp[i-x]);
        }
        if(minCoinRequired==INT_MAX)
        dp[i]=INT_MAX;
        else
        dp[i]=minCoinRequired+1;
    }
    if(dp[amount]==INT_MAX)
    return -1;
    else
    return dp[amount];
}

int main() {
    vector<int>coins={2};
    int amount=3;
    cout<<solve(coins,amount);
}
