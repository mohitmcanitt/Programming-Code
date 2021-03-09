// LeetCode 239 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        multiset<int>window;
        int windowStartAt=0,windowEndAt=k-1;
        for(int i=0;i<k;i++)
            window.insert(nums[i]);
       while(windowEndAt<nums.size()) 
       {
           ans.push_back(*window.rbegin());  // push last element of multiet
           if(windowEndAt+1==nums.size())
               break;
           window.erase(window.find(nums[windowStartAt])); // delete first value of window
           window.insert(nums[windowEndAt+1]);    // insert next element in window
           
           windowStartAt++;  // increment windowStart
           windowEndAt++;   // Increment Window EndAt
       }
      return ans;
    }
