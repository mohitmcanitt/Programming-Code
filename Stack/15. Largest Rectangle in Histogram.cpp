/*
Leetcode 84 : https://leetcode.com/problems/largest-rectangle-in-histogram/ 

Stock span is sub problem for this question

Using stack
step1: Count number of elements in left which is greater than current elment
step2: Count number of elements in right which is greater than current element

step3 : area cover by current element will be (count in left+ count in right - 1) * value of element
stpe4 : among all areas of each index , maximum will be our answer.

Use concept of leftSmaller in left  and leftSmaller in right
We will store index in stack

*/
void nextSmallerLeft(vector<int>&heights,vector<int>&ans)
    {
        stack<int>st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())
            {
                ans.push_back(i+1);
                st.push(i);
            }
            else if(heights[st.top()]<heights[i])  // agar top ka area chota hai to current element expand nhi hoga
            {
                ans.push_back(1);
                st.push(i);
            }
            else
            {
                while(!st.empty() and heights[st.top()]>=heights[i]) // agar top ka area bada hai to current element expand hoga  until we encounter smaller element
                    st.pop();
                if(st.empty())
                {
                    ans.push_back(i+1);
                    st.push(i);
                }
                else
                {
                    ans.push_back(i-st.top());
                    st.push(i);
                }
                    
            }
        }
    }
    
    void nextSmallerRight(vector<int>&heights,vector<int>&ans)
    {
        int n=heights.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(n-i);
                st.push(i);
            }
            else if(heights[st.top()]<heights[i])
            {
                ans.push_back(1);
                st.push(i);
            }
            else
            {
                while(!st.empty() and heights[st.top()]>=heights[i])
                    st.pop();
                if(st.empty())
                {
                    ans.push_back(n-i);
                    st.push(i);
                }
                else
                {
                    ans.push_back(st.top()-i);
                    st.push(i);
                }
            }
        }
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left;
        nextSmallerLeft(heights,left);
        
        vector<int>right;
        nextSmallerRight(heights,right);
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            int temp=(left[i]+right[i]-1)*heights[i];
            ans=max(ans,temp);
        }
        return ans;
        
    }
