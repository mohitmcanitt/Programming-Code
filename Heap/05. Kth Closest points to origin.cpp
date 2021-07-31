// Leetcode problem link : https://leetcode.com/problems/k-closest-points-to-origin/
class comparater{
        public:
        bool operator()(pair<int,int>p1,pair<int,int>p2)
        {
            return ((p1.first*p1.first)+(p1.second*p1.second))<((p2.first*p2.first)+(p2.second*p2.second)); // max heap
            
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparater>pq;
        for(int i=0;i<k;i++)
            pq.push({points[i][0],points[i][1]});
        for(int i=k;i<points.size();i++)
        {
            auto it=pq.top();
            int top_distance=(it.first*it.first)+(it.second*it.second);
            int current_points=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(current_points<top_distance)
            {
                pq.pop();
                pq.push({points[i][0],points[i][1]});
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
