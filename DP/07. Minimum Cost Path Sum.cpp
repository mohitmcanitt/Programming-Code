/* Memoization Recursion
int solve(vector<vector<int>>&dp,vector<vector<int>>grid,int i,int j)
    {
        if(i<0 or j<0)
            return INT_MAX;
        else if(i==0 and j==0)
            return grid[0][0];
        else if(dp[i][j]!=-1)
            return dp[i][j];
        else
        {
            int cost= grid[i][j]+min(solve(dp,grid,i,j-1),solve(dp,grid,i-1,j));
            dp[i][j]=cost;
            return cost;
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        int row=grid.size();
        int col=grid[0].size();
       vector<vector<int>>dp(row,vector<int>(col,-1));
        retutn solve(dp,grid,row-1,col-1);
   
    }
    */

/* Tabulation

 int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp;
        dp=grid;
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(i==row-1 and j==col-1) // bottom-right
                    dp[i][j]=grid[i][j];
                else if(i==row-1)  // bottom row
                    dp[i][j]+=dp[i][j+1];
                else if(j==col-1) // right colum
                    dp[i][j]+=dp[i+1][j];
                else // in middle of grid
                    dp[i][j]+=min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0]; 
    }
    
    */
