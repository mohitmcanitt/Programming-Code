/*
BFS------> Breadth First 
Steps:
1. Take stack and a set
2. stack will store the vertex
3. set will store visited vertex
4. put source vertex in set and stack
5. Pop from stack
6. Print top element
7. Push its child which is not visited in stueue and set
7. repeat 5-7 untill stack is not empty

Input:
Graph example taken from below link
https://www.youtube.com/watch?v=stRst6p9s8NVg

Output:

A-->B,S,
B-->A,
C-->S,D,E,F,
D-->C,
E-->C,H,
F-->G,C,
G-->S,F,H,
H-->E,G,
S-->A,C,G,
DFS, If source is C
C S A B G F H E D 
*/


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<char,vector<char>>m;

    public:
    Graph(int v)
    {
        V=v;
    }

    void addEdge(char u,char v)
    {
        m[u].push_back(v);
        m[v].push_back(u);
    }
    
    void printEdge()
    {
        for(auto vertex:m)
            {
                cout<<vertex.first<<"-->";
                for(auto nbhrs:vertex.second)
                cout<<nbhrs<<",";
                cout<<endl;
            }
    }

    void dfs_helper(char src,map<char,bool>&visited)
    {
        cout<<src<<" ";
        visited[src]=true;

        for(auto node:m[src])
            {
                if(!visited[node])
                dfs_helper(node,visited);
            }
    }

    void dfs_recursive(char src)
    {
        map<char,bool>visited;

        for(auto x:m)   // Make each vertex as non visited
        visited[x.first]=false;

        dfs_helper(src,visited);

    }
};
int main()
{
    Graph g(10);
    g.addEdge('A','B');
    g.addEdge('A','S');
    g.addEdge('S','C');
    g.addEdge('C','D');
    g.addEdge('S','G');
    g.addEdge('G','F');
    g.addEdge('C','E');
    g.addEdge('C','F');
    g.addEdge('E','H');
    g.addEdge('G','H');
    g.printEdge();

    g.dfs_recursive('C');

}
