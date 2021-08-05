 int lenOfLongSubarr(int nums[],  int N, int k) 
    { 
        // Complete the function
        unordered_map<int,int>um;  // presum --> index
        um[0]=-1;
        int preSum=0;
        int size=0;
        for(int i=0;i<N;i++)
        {
            preSum+=nums[i];
            if(um.find(preSum-k)!=um.end())
                size=max(size,i-um[preSum-k]);
            if(um.find(preSum)==um.end()) 
                um[preSum]=i;
        }
        return size;
    } 
