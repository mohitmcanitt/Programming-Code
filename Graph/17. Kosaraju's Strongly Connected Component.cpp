/*
Strongly Connected Component 
A direcred graph is strongly connected if there exists path between
every pairs of vertices.

Kosaraju's helps in finding number of strongly connected component in a graph

step1: start with any vertex
step2: apply dfs to vertex
step3. Visit its neighbours
step4. Once all neighbours are visited , while returning back add current src to ordering vector
step5: reverse the given graph.
step6. Again Do dfs , but  this time from Right to left of ordering vector.

input :
7
8
0 1 
1 2
2 0
3 0
4 3
5 3
3 6
6 5


Output:

Total number of strongly connected component is 3
4 
3 5 6 
0 2 1 
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<bool>&visited,vector<int>&v,vector<int>adj[])
{
    visited[src]=true;
    for(auto nbhrs:adj[src])
    {
        if(visited[nbhrs]==false)
            dfs(nbhrs,visited,v,adj);
    }
    v.push_back(src);
}

void getOrdering(int v,vector<int>&ordering,vector<int>adj[])
{
    vector<bool>visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            dfs(i,visited,ordering,adj);
    }
}

void dfs2(int src,vector<bool>&visited,vector<int>&ans,vector<int>new_adj[])
{
    visited[src]=true;
    ans.push_back(src);
    for(auto nbhrs:new_adj[src])
    {
        if(visited[nbhrs]==false)
            dfs2(nbhrs,visited,ans,new_adj);
    }
}

void getStronglyConnectedComponent(int v,vector<vector<int>>&ans,vector<int>new_adj[],vector<int>&ordering)
{
    vector<bool>visited(v,false);
    for(int i=ordering.size()-1;i>=0;i--)
    {
        vector<int>v;
        if(visited[ordering[i]]==false)
        {
            dfs2(ordering[i],visited,v,new_adj);  
            ans.push_back(v);
        }
         
        
    }
}



vector<vector<int>> solve(int v,vector<int>adj[])
{
    // Steps 1:
    // get linear ordering based on finish time

    vector<int>ordering;
    getOrdering(v,ordering,adj);

    // Steps 2:
    // Reverse graph 
    vector<int>new_adj[v];
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
            new_adj[x].push_back(i);
    }
    
    // STEPS 3
    // Call DFS with source right to left from ordering vector

    vector<vector<int>>ans;
    getStronglyConnectedComponent(v,ans,new_adj,ordering);
    return ans;
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
    }
    vector<vector<int>>scc=solve(v,adj);
    cout<<"Total number of strongly connected component is "<<scc.size()<<endl;
    for(auto x:scc)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;    
    }
}
