// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#

int countWays(int n)
    {
        // your code here
       long long int m=1000000007;
        vector<long long int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                dp[i]=dp[i+1];
            else 
                dp[i]=((dp[i+1])%m+(dp[i+2])%m)%m;
        }
            
        return dp[0];    
    }
