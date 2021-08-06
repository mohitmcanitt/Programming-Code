// Method 1: Using product division   
vector<int> productExceptSelf(vector<int>& nums) {  
        int n=nums.size();
        vector<int>ans(n,0);
        int count_zeroes=0;
        int pro=1;
        for(auto x:nums)
        {
            if(x==0)
                count_zeroes++;
            else
                pro*=x;
        }
        if(count_zeroes>1)  // agar 2 or more zeroes the product will coontains only zeroes
            return ans;
        else if(count_zeroes==1)
        {
            for(int i=0;i<n;i++)
                if(nums[i]==0)
                    ans[i]=pro;
        }
        else
        {
            for(int i=0;i<n;i++)
                    ans[i]=pro/nums[i];
        }
            return ans;
    }

// Method 2: Using precomputing left product and right product 
// O(n) and 0(n)
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre_pro(n);
        vector<int>suff_pro(n);
        
        pre_pro[0]=1;
        suff_pro[n-1]=1;
        
        for(int i=1;i<n;i++)
            pre_pro[i]=pre_pro[i-1]*nums[i-1];
            
        for(int i=n-2;i>=0;i--)
            suff_pro[i]=suff_pro[i+1]*nums[i+1];
        for(int i=0;i<n;i++)
            nums[i]=pre_pro[i]*suff_pro[i];
        return nums;
    }
// Method 3: No extra space

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        vector<long long int>left(n,1);
        left[0]=nums[0];
        for(int i=1;i<n;i++)
        left[i]=nums[i]*left[i-1];
        
        long long int pro=1;
        for(int i=n-1;i>0;i--)
        {
            long long int temp=nums[i];
            nums[i]=pro*left[i-1];
            pro*=temp;
        }
        nums[0]=pro;
        return nums;
    }
