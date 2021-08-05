/*
Working is similar to Binary Search.
if key element is not matched with arr of mid.

Now comes in which part we have to move either left or right

observation :
If we carefully observe , either left subarray from mid or right subarray from mid will be sorted
so now we will check does my target lies in between in sorted part or not
based on that we will move
*/

int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[low]<=nums[mid])  // left part sorted
            {
                if(target>=nums[low] and target<nums[mid])
                 high=mid-1;
                else
                    low=mid+1;
            }
            else
                {
                if(target>nums[mid] and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        
        }
        return -1;
    }
