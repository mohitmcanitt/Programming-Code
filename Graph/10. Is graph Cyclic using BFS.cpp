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

/*

#include<bits/stdc++.h>
using namespace std;

// Only for undirected graph

bool isCyclic(int V,vector<int>adj[])
{
    bool visited[V]={false};
    int par[V];

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            queue<int>q;
            q.push(i);
            par[i]=-1;
            visited[i]=true;
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                for(auto nbhrs:adj[temp])
                {
                    if(visited[nbhrs]==true and par[nbhrs]!=temp)
                    {
                        for(int i=0;i<V;i++)
                           cout<<i<<" "<<par[i]<<endl;
                         return true;                           
                    }
                       
                    else if(visited[nbhrs]==false) 
                        {
                            visited[nbhrs]=true;
                            par[nbhrs]=temp;
                            q.push(nbhrs);
                        }   
                }
            }
            
        }
        
       
    }
    
    return false;
  
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    if(isCyclic(v,adj))
        cout<<"Graph Contains Cycle";
    else
        cout<<"Graph Doesn't contains any cycle";    
}
/*
GFG code
#include<bits/stdc++.h>
using namespace std;

// Only for undirected graph

bool isCyclic(int V,vector<int>adj[])
{
    bool visited[V]={false};
    int par[V];

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            queue<int>q;
            q.push(i);
            par[i]=-1;
            visited[i]=true;
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                for(auto nbhrs:adj[temp])
                {
                    if(visited[nbhrs]==true and par[nbhrs]!=temp)
                    {
                        for(int i=0;i<V;i++)
                           cout<<i<<" "<<par[i]<<endl;
                         return true;                           
                    }
                       
                    else if(visited[nbhrs]==false) 
                        {
                            visited[nbhrs]=true;
                            par[nbhrs]=temp;
                            q.push(nbhrs);
                        }   
                }
            }
            
        }
        
       
    }
    
    return false;
  
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    if(isCyclic(v,adj))
        cout<<"Graph Contains Cycle";
    else
        cout<<"Graph Doesn't contains any cycle";    
}


*/
