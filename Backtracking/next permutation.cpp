// https://www.youtube.com/watch?v=TOvWyFT0xCw
void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
            reverse(nums.begin(),nums.end());
        else
        {
            int prev=idx;
            for(int j=idx+1;j<n;j++)
            {
                if(nums[prev]>=nums[j] and nums[j]>nums[idx-1])
                    prev=j;
            }
            swap(nums[prev],nums[idx-1]);
            reverse(nums.begin()+idx,nums.end());
        }
        
    }
