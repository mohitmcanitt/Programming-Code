
#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>coins,int amount,int dp[])
{
    if(amount==0)
    return 0;  

    if(dp[amount]!=0)
    return dp[amount];

    int res=INT_MAX;

    for(int i=0;i<coins.size();i++)
    {
        if(amount-coins[i]>=0)
        {
             int subprob = solve(coins,amount-coins[i],dp);
             if(subprob!=INT_MAX and subprob!=-1)
              res=min(res,subprob+1);
        }
    }
    dp[amount]=res;
    return dp[amount];
}

int main() {
    vector<int>coins={83,186,408,419};
    int amount=6249;
    int dp[10000]={0};
    cout<<solve(coins,amount,dp);
}
