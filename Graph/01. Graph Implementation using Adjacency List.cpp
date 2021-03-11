//Graph implementation usiong adjancency list
/*
Input

 0---1
 |  /| \
 | / |  2
 4---3 /
 
 Output
 
For vertex 0 -->1,4,
For vertex 1 -->0,2,3,4,
For vertex 2 -->1,3,
For vertex 3 -->1,2,4,
For vertex 4 -->0,1,3,

*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v)
    {
        V=v;
        l= new list<int>[v];
    }
    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printEdge()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"For vertex "<<i<<" -->";
            for(auto nbhrs:l[i])
            cout<<nbhrs<<",";
            cout<<endl;
        }
    }

};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.printEdge();
}
