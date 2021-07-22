// Leetcode 42 : https://leetcode.com/problems/trapping-rain-water/
int trap(vector<int>& height) {     
        int n=height.size();
        if(n<=2)
            return 0; 
        
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        
        leftMax[0]=0;
        rightMax[n-1]=0;
        
        for(int i=1;i<n;i++)
            leftMax[i]=max(leftMax[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--)
            rightMax[i]=max(rightMax[i+1],height[i+1]);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int curr_bar_holding=min(leftMax[i],rightMax[i])-height[i];
             sum+=curr_bar_holding>0?curr_bar_holding:0;
        }
              
        return sum;
        
    }
