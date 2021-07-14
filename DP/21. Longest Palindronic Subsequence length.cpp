// Leetcode 516 
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb". 

    // In subsequence
    // if extrems are not equal take max(dp[i][j-1],dp[i+1][j])
    // if extremes are equal , take 2+dp[i+1][j-1];
    
    // In substring 
    // If extremes are not equal, dp[i][j]=false
    // if extremes are equal , dp[i][j]=dp[i+1][j-1]; // depends on middle part
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,1));
        // two length
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                dp[i][i+1]=2;  
        }
        
        for(int i=2;i<n;i++)
        {
            int k=0;
            for(int j=i;j<n;j++)
            {
                if(s[k]==s[j])
                    dp[k][j]=2+dp[k+1][j-1];
                else
                    dp[k][j]=max(dp[k+1][j],dp[k][j-1]);
                k++;
            }
        }
        return dp[0][n-1];
        
    }
