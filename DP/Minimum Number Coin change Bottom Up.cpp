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

/*

long dp[10001];
    int coinChange(vector<int>& coins, int amount) {
        
        for(int curr_amt=1;curr_amt<=amount;curr_amt++)
        {
            long min_coins=INT_MAX; // minimum coins required to make change of current amount
            for(auto denomination:coins)
            {
                if(curr_amt-denomination>=0)
                    min_coins=min(min_coins,1+dp[curr_amt-denomination]);
            }
            dp[curr_amt]=min_coins;
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
*/
