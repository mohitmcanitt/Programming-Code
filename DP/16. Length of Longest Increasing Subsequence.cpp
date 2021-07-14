// leetcode 300
int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            int max_len=INT_MIN;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    max_len=max(max_len,dp[j]);
            }
            if(max_len!=INT_MIN)
            dp[i]=max_len+1;
        }
       
        return *max_element(dp.begin(),dp.end());
    }Lee
