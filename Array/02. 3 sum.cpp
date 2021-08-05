 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums)); // sort it
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++)  
        {
            if(i==0 or nums[i]!=nums[i-1])  // 
            {
                int target=-(nums[i]);
                int l=i+1;
                int r=n-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]==target)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        while(l<r and nums[l]==nums[l+1]) //
                            l++;
                        while(l<r and nums[r]==nums[r-1])  //
                            r--;
                        l++;
                        r--;
                    }
                    else if(nums[l]+nums[r]<target)
                        l++;
                    else 
                        r--;   
                }
            }
        }
        return ans;
    }
