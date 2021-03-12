/*
Connected Components in an undirected graph

1) Initialize all vertices as not visited.
2) Do following for every vertex 'v'.
       (a) If 'v' is not visited before, call DFS(v)
       (b) Print new line character

DFS(v)
1) Mark 'v' as visited.
2) Print 'v'
3) Do following for every adjacent 'u' of 'v'.
     If 'u' is not visited, then recursively call DFS(u)

INPUT:
https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/

OUTPUT:

Connected component 0 :-> 0 1 2 
Connected component 1 :-> 3 4 
Connected component 2 :-> 5 6 

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,list<int>>m;

    public:
    Graph(int v)
    {
        V=v;
    }

    void addEdge(int u,int v)
    {
        m[u].push_back(v);
        m[v].push_back(u);
    }
    
    void dfs_helper(int src,map<int,bool>&visited)
    {
        cout<<src<<" ";
        visited[src]=true;

        for(auto node:m[src])
            {
                if(!visited[node])
                dfs_helper(node,visited);
            }
    }

   
    void connecetedComponent()
    {
         map<int,bool>visited;

        for(auto x:m)   
        visited[x.first]=false;

        int cnt=0;
        for(auto x:m)
        {
            if(!visited[x.first])
            {
                cout<<"Connected component "<<cnt<<" :-> ";
                dfs_helper(x.first,visited);
                cout<<endl;
                cnt++;
            }
                
            
        }
    }


};
int main()
{
    Graph g(7);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(5,6);

    g.connecetedComponent();

}
