/*
Implemantaion of weighted graph (directed)
Image of graph
https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-2-weighted-graph/


Output :
Neighbours of vertex 0 is --> vertex 1 and their weight is 10, vertex 2 and their weight is 3, vertex 3 and their weight is 2,
Neighbours of vertex 1 is --> vertex 3 and their weight is 7,
Neighbours of vertex 2 is --> vertex 3 and their weight is 6,

*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,vector<pair<int,int>>>m;  
    public:
    Graph(int v)
    {
        V=v;
    }
    void addEdge(int u,int v,int weight)
    {
        m[u].push_back(make_pair(v,weight));
    }

    void printgraph()
    {
        for(auto x:m)
        {
            cout<<"Neighbours of vertex "<<x.first<<" is -->";
            for(auto nbhr:x.second)
            {
                cout<<" vertex "<<nbhr.first<<" and their weight is "<<nbhr.second<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,3);
    g.addEdge(0,3,2);
    g.addEdge(1,3,7);
    g.addEdge(2,3,6);
    g.printgraph();
}
