// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int>st;
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           {
               st.push(i);
               ans.push_back(i+1);
           }
           else if(price[st.top()]>price[i])
            {
                ans.push_back(i-st.top());
                st.push(i);
                
            }   
            else
            {
                while(!st.empty() and price[st.top()]<=price[i])
                    st.pop();
                if(st.empty())
                {
                    st.push(i);
                    ans.push_back(i+1);
                }
                else
                {
                    ans.push_back(i-st.top());
                    st.push(i);
                    
                }
            }
       }
