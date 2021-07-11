// https://leetcode.com/problems/climbing-stairs/
// Memoization Problem
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
// Tabular Form
 int solve2(int n)
 {
     dp[0]=1;
     for(int i=1;i<=n;i++)
     {
         if(i==1)
             dp[i]=dp[i-1];
         else
             dp[i]=dp[i]+dp[i-2];
     }
     return dp[n];
 }     
    
    int climbStairs(int n) {
        solve(n);
        return dp[n];
    }
