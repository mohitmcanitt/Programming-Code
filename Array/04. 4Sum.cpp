// Watch Take u forward video
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i!=0 and nums[i]==nums[i-1])
                 continue;                  
            for(int j=i+1;j<n-2;j++)
            {
               if(j==i+1 or nums[j]!=nums[j-1])
               {
                  int new_target=target-(nums[i]+nums[j]);
                 int l=j+1;
                 int r=nums.size()-1;
                 while(l<r)
                 {
                     if(nums[l]+nums[r]==new_target)
                     {
                         vector<int>temp;
                         temp.push_back(nums[i]);
                         temp.push_back(nums[j]);
                         temp.push_back(nums[l]);
                         temp.push_back(nums[r]);
                         ans.push_back(temp);
                         while(l<r and nums[l]==nums[l+1])
                             l++;
                         while(l<r and nums[r]==nums[r-1])
                             r--;
                         l++;
                         r--;
                     }
                     else if(nums[l]+nums[r]<new_target)
                         l++;
                     else
                         r--;
                 } 
               }
                 
            }
        }
        return ans;
    }
