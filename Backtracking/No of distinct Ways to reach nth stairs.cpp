// https://leetcode.com/problems/climbing-stairs/

int dp[1001]={0};
    int solve(int n)
    {
       
        if(n<=2)
            return dp[n]=n;
        if(dp[n])
            return dp[n];
        int sum=solve(n-1)+solve(n-2);
        dp[n]=sum;
        return sum;
            
    }
    
    
    int climbStairs(int n) {
        solve(n);
        return dp[n];
    }
