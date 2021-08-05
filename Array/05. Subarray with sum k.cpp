int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>um;
        um[0]=1;
        int preSum=0;
        int size=0;
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            if(um.find(preSum-k)!=um.end())
                size=max(size,i-um[preSum-k]);
            else
                um[preSum]=i;
        }
        return count;
}
