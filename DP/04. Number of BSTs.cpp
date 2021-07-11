/*
Number of BSTs 
0-0
1-1
2-2
3-5
4-14

*/


int dp[20]={0}; 
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i]+=dp[j]*dp[i-j-1];
        return dp[n];
    }
