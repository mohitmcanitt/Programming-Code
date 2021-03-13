/*
--- Distance of each node from given src node --- 
step 1: create a map of vertex and their distance from src node
step 2: Initialize each node distance from src equal to INT_MAX
        except for the src node
step 3: push src node to queue
step 4: temp= pop front node 
step 5: insert its child (if it not visited, dist[nbhrs]==INT_MAX ) 
        and distance[child]=distance[temp]+1;
step 6: repeat step 4-5 until queue is not empty        

Output:
Distance from sourece node to 0 is 0
Distance from sourece node to 1 is 1
Distance from sourece node to 2 is 2
Distance from sourece node to 3 is 1
Distance from sourece node to 4 is 2
Distance from sourece node to 5 is 3

*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,list<int>>adjList;
    public:
    Graph(int v)
    {
        this->V=v;
    }
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void shortestDist_from_Src_to_nodes(int src)
    {
        map<int,int>dist; // store vertex and their distance
        for(auto node:adjList)  // Mark all nodes distance from src equals to INT_MAX
            dist[node.first]=INT_MAX;
        dist[src]=0; // src to src 0 distance

        queue<int>q;
        q.push(src);

        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            for(auto nbhrs:adjList[parent])
            {
                if(dist[nbhrs]==INT_MAX)
                {
                    q.push(nbhrs);
                    dist[nbhrs]=dist[parent]+1;
                }
            }
        }

        for(auto x:dist)
        {
            cout<<"Distance from sourece node to "<<x.first<<" is "<<x.second<<endl;
        }
    }

};


int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.shortestDist_from_Src_to_nodes(0);

}
