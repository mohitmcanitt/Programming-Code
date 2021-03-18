/*
Cycle detection using BFS

 For every visited vertex ‘v’,
  if there is an adjacent ‘u’ 
  such that u is already visited 
  and u is not a parent of v,
   then there is a cycle in the graph. 
   If we don’t find such an adjacent for any vertex, 
   we say that there is no cycle.


Refer : https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>adjList;
    public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printEdge()
    {
        for(auto x:adjList)
        {
            cout<<x.first<<"-->";
            for(auto nbhrs:x.second)
                cout<<nbhrs<<",";
                cout<<endl;
        }
    }
    bool isCyclic()
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;
        int src=adjList.begin()->first;

        q.push(src);
        visited[src]=true;
        parent[src]=-1;
       
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:adjList[u])
            {
                if(visited[v]==false)
                {
                    q.push(v);
                    visited[v]=true;
                    parent[v]=u;
                }
                else if(parent[u]!=v)
                  return true;
            }
        }
        return  false;
    }


};
using namespace std;
int main() {
    Graph g;
    g.addEdge(0,1);
   // g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printEdge();  

    if(g.isCyclic())
    cout<<"Graph is cyclic \n";
    else
    cout<<"Graph is not cyclic\n";
}
