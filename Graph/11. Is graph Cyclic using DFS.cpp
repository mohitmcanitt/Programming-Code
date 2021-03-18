/*
Refer : https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
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
    bool cycle_helper(int src,unordered_map<int,bool>&visited,int parent)
    {
        visited[src]=true;
        for(auto nbhrs:adjList[src])
        {
            if(visited[nbhrs]==false)
            {
                bool cycle_mila=cycle_helper(nbhrs,visited,src);
                if(cycle_mila)
                return true;
            }
            else if(nbhrs!=parent)
            return true;
        }
        return false;
    }


    bool isCyclic()
    {
        unordered_map<int,bool>visited;
        
        int src=adjList.begin()->first;

        return cycle_helper(src,visited,-1);
       
    }


};
using namespace std;
int main() {
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printEdge();  

    if(g.isCyclic())
    cout<<"Graph is cyclic \n";
    else
    cout<<"Graph is not cyclic\n";
}
