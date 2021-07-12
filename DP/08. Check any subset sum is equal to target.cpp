bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool dp[N+1][sum+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else
                {
                    bool case1=dp[i-1][j]; // khud run nhi bnayega
                    bool case2=false;    // khud run bnayega
                    if(arr[i-1]<=j)
                    {
                        if(dp[i-1][j-arr[i-1]])
                            case2=true;
                    }
                    dp[i][j]=case1 or case2;
                }
                    
            }
        }
        return dp[N][sum];
    }
