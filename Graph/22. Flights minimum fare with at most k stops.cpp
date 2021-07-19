
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<pair<int,int>>>g(n);
        for(auto x:flights)
            g[x[0]].push_back({x[1],x[2]});
        pq.push(make_tuple(0,src,0));  // weight src noOfstops
        while(!pq.empty())
        {
            auto [cost,u,stops]=pq.top();
            pq.pop();
            
            if(u==dst)
                return cost;
            if(stops>K)
                continue;
            for(auto child:g[u])
            {
                auto [v,w]=child;
                pq.push(make_tuple(cost+w,v,stops+1));
            }
                
        }
        return -1;
        
    }
