vector<int> findErrorNums(vector<int>& nums) {
  
        int missing_number,duplicate,i=0;
        while(i<nums.size())
        {
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else
                i++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i+1!=nums[i])
            {
            missing_number=i+1;
                duplicate=nums[i];
            }
        }
        return {duplicate,missing_number};
 }

/* 
Input 
2 3 3 4
output
3 1


*/
