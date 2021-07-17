/*
https://www.geeksforgeeks.org/shortest-path-unweighted-graph/

For calculating single shortest path without any weight
Use Breadth First Technique;

For distance:
intialize all vertices distance from source is INT_MAX;
for source distance intiliazed with zero

For all non visited node (if dist[node]==INT_MAX , no need to create any visited array)
store dist[node]=dist[parent]+1;

For Paths:
we will store parent of node ,by par[nbhrs]=src

Input
8
10 
1 2 
1 0
0 3
3 7
3 4
7 4
7 6
4 6
4 5
6 5
2
6

Output
Shortest path length is:5
6 7 3 0 1 2
*/


#include<bits/stdc++.h>
using namespace std;

void solve(int source,int destination,int v,vector<int>adj[])
{
    vector<int>dist(v,INT_MAX);
    vector<int>par(v);
    queue<int>q;
    q.push(source);
    dist[source]=0;
    par[source]=source;
    
    while(!q.empty())
    {
        int src=q.front();
        q.pop();
        if(src==destination)
            break;
        for(auto nbhrs:adj[src])
        {
            if(dist[nbhrs]==INT_MAX)
            {
                dist[nbhrs]=dist[src]+1;
                par[nbhrs]=src;
                q.push(nbhrs);
            }
        }
    }
    if(dist[destination]==INT_MAX) 
        cout<<"No path exists"<<endl;
    else
    {
        cout<<"Shortest path length is:"<<dist[destination]<<endl;
        while(source!=destination)
        {   
            cout<<destination<<" ";
            destination=par[destination];
        }
        cout<<source<<endl;
    }
    
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    while(e--)
    {
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    int source,destination;
    cin>>source>>destination;
    solve(source,destination,v,adj);
}
