// 1 1 2 2 0 1 2 2 1 0 1 2 0 2 1
/*

 Three pointer aproach : low,mid and high
 
 0 to low-1 will store 0;
 low to high will store 1;
 high+1 to end(n) store 2;
 
 mid element will be used for processing 
 
 case 1: if arr[mid]==1
            only increment mid++;
 case 2: if arr[mid]==0
        swap(arr[low],arr[mid])
        increment low and high
 case 3: if arr[mid]==2 
        swap(arr[mid],arr[high])
        only decrement high by 1;
        no need to increment mid as the value at mid now can either 0,1 or 2
        
        
https://leetcode.com/problems/sort-colors/  
*/

void sort012(vector<int>& nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
