    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>um;  // remainder and freq;
        int ans=0;
        um[0]=1;
        int preSum=0;
        int rem;
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            rem=preSum%k;
            if(rem<0)
                rem+=k;
            if(um.find(rem)!=um.end())
                ans+=um[rem];
            um[rem]++;
        }
        return ans;
        
    }
