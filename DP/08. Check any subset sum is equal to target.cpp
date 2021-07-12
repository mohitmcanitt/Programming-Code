#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>v,int target)
{
    int n=v.size();
    bool dp[n+1][target+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(i==0 and j==0)
                dp[i][j]=true;
            else if(i==0)   
                dp[i][j]=false;
            else if(j==0) 
                dp[i][j]=true;
            else
            {
               if(dp[i-1][j]==true)
                    dp[i][j]=true;
                else
                {
                    if(v[i-1]>j)
                        dp[i][j]=false;
                    else
                        dp[i][j]=dp[i-1][j-v[i-1]];    
                }    
            }    
        }
    }
  return dp[n][target];
}


int main() {
    vector<int>v={3, 34, 4, 12, 5, 2};
    if(solve(v,9))
        cout<<"\nPresent";
        else
        cout<<"\nAbsent";
}
