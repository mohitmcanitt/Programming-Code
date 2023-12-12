// Approach 1:

int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int current_product = ((nums[i]-1) * (nums[j]-1));
                ans = max(ans,current_product);
            }    
        }
        return ans;
    }
