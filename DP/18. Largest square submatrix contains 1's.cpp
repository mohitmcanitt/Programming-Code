/*
create a 2-d dp array
copy given matrix

A cell not being (last row ,col or containing zero)
1. value of current cell = 1+ min(1-down bottom cell,1-right cell, 1 down diagonal)
 for(int i=mat.size()-2;i>=0;i--) // not including last row
        {
            for(int j=mat[0].size()-2;j>=0;j--)  // not including last column 
            {
                if(dp[i][j]!=0)  // not including zeroes
                dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
            }
        }
*/



int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<vector<int>>dp;
        dp=mat;
        for(int i=mat.size()-2;i>=0;i--)
        {
            for(int j=mat[0].size()-2;j>=0;j--)
            {
                if(dp[i][j]!=0)
                dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
             ans=max(ans,dp[i][j]);
            }
           
                
        }
        return ans;
    }
