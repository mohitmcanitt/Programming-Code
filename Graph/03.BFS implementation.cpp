/*

BFS------> Breadth First 

Steps:
1. Take queue and a set
2. Queue will store the vertex
3. set will store visited vertex
4. put source vertex in set and queue
5. Pop from queue
6. Print top element
7. Push its child which is not visited in queue and set
7. repeat 5-7 untill queue is not empty

Input:
Graph example taken from below link
https://www.youtube.com/watch?v=QRq6p9s8NVg

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
BFS, If source is C
C S D E F A G H B 

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

    void bfs(char src)
    {
        set<char>s;
        s.insert(src);
        queue<char>q;
        q.push(src);

        while(!q.empty())
        {
            char temp=q.front();
            q.pop();
            for(auto nbhr:m[temp])
            {
                if(!s.count(nbhr))
                    {
                        s.insert(nbhr);
                        q.push(nbhr);
                    }
            }
            cout<<temp<<" ";
        }
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

    g.bfs('C');

}

