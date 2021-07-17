/*
Input 
9
14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
2 8 2
8 6 6
2 5 4
6 5 2
2 3 7
3 4 9
3 5 14
5 4 10

Output

0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14

*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(int V,vector<pair<int,int>>adj[])
{
    vector<int> dist(V,INT_MAX);
	set<pair<int,int>> s; // {weight,vertex} reason --> smallere weight should be present at front

    dist[0] = 0; // initialize source dist with 0
	s.insert({0,0}); // push source with weight

    while(!s.empty()) // run untill set is not empty
    {
        auto it=s.begin();  
        int distTillNow=it->first; // u total weight till now
        int u=it->second;   // vertex u
        s.erase(it);  // pop it from set
       

        for(auto nbhrs:adj[u])  // visit u adjcaent
        {
            int wt_u_to_v=nbhrs.second;  // weight of vertex v
            int v=nbhrs.first;    // vertex v
            if(distTillNow+wt_u_to_v<dist[v])  // (if optimal weight  till vertex u + distance between u->v ) is less than weight of v... then include in set and dist[v]=new weight
                {
                    // if v is already exists with weight grater than current , then delete and insert new optimal
                    auto it=s.find({dist[v],v});
                    if(it!=s.end())
                        s.erase(it);
                     dist[v]=distTillNow+wt_u_to_v; // new optimal weight from u to v    
                    s.insert({dist[v],v});
                }
        }
    }
    for(int i=0;i<V;i++)
        cout<<i<<" "<<dist[i]<<endl;
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>adj[v];
    while(e--)
    {
        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back({d,w});
    }
      
    dijkstra(v,adj);
}
