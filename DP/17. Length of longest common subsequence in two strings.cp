/*
If char at position x of s1 and position y of s2 is same
then we will add 1 in ans and move postion of x and y by 1 to solve for remaining 

else if char are not equal then 
  case 1: increase x by 1 and y remain unchanged solve(x+1,y)
  case 2: increase y by 1 and x remain unchanged solve(x,y+1)
  
  add max(case1,case2) in out answers 
  
*/ 
  

// Backtracking

 int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        if(x==0 or y==0)
            return 0;
        else if(s1[x-1]==s2[y-1])
            return 1+lcs(x-1,y-1,s1,s2);
        else
            return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
    }
    
// Memoization

int solve(int x,int y,string s1,string s2,vector<vector<int>>&dp)
    {
        if(x<0 or y<0)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        else if(s1[x]==s2[y])
            return dp[x][y]=1+solve(x-1,y-1,s1,s2,dp);
        else
            return dp[x][y]=max(solve(x-1,y,s1,s2,dp),solve(x,y-1,s1,s2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
   // Tabulation
   /* if character at i and j is same dp[i][j]=1+dp[i-1][j-1] means previous diagonal cell
   /* If character at i and is not same then dp[i][j]=max(dp[i-1][j],dp[i][j-1]) means 1 left and 1 up
        
   int longestCommonSubsequence(string text1, string text2) {
        
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]+=(dp[i-1][j-1]+1);
                else
                    dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n1][n2];
        
        
    }
    
