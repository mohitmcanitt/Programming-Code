// Problem link leetcode 658 : https://leetcode.com/problems/find-k-closest-elements/

class comparater{
        public:
        bool operator()(pair<int,int>p1,pair<int,int>p2)
        {
            return abs(p1.first-p1.second)<abs(p2.first-p2.second); // max heap
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparater>pq;
        for(int i=0;i<k;i++)
            pq.push({arr[i],x});
        for(int i=k;i<arr.size();i++)
        {
            int top_distance=abs(pq.top().first-pq.top().second);
            int current_distance=abs(arr[i]-x);
            if(current_distance<top_distance)
            {
                pq.pop();
                pq.push({arr[i],x});
            }
        }
        vector<int>ans(k);
        int i=k-1;
        while(!pq.empty())
        {
            ans[i--]=pq.top().first;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
