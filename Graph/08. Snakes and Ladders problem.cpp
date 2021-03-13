/*
Minimum number of dice Throws
required to reach destination(36)
starting from source.
Find shortest path

Leetcode 909 : https://leetcode.com/problems/snakes-and-ladders/

*/


#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>adjList;
    public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
    }
    void printGraph()
    {
        for(auto x:adjList)
        {
            cout<<x.first<<"-->";
            for(auto y:x.second)
            cout<<y<<",";
            cout<<endl;
        }
    }

    int shortestDistance(int src,int dest,vector<int>&v)
    {
        map<int,int>dist; 

        for(auto x:adjList)
            dist[x.first]=INT_MAX;

        dist[src]=0;    

        map<int,int>path;
        path[src]=src;
        queue<int>q;
        q.push(src);  
        while(!q.empty() and dist[dest]==INT_MAX)
        {
            int parent=q.front();
            q.pop();
            for(auto nbhrs:adjList[parent])
            {
                if(dist[nbhrs]==INT_MAX)
                {
                    path[nbhrs]=parent;
                    q.push(nbhrs);
                    dist[nbhrs]=dist[parent]+1;
                }
            }
        }  
        int ans=dist[dest];
        while(dest!=src)
        {
            v.push_back(dest);
            dest=path[dest];
        }
        v.push_back(src);

        return ans;
    }
};


int main()
{
    Graph g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[17]=-13;
    board[18]=11;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    for(int i=1;i<36;i++)
    {
        for(int dice=1;dice<=6;dice++)
            {
                int j=i+dice;
                j+=board[j];
                if(j<=36)
                 g.addEdge(i,j);
            }
    }
    g.addEdge(36,36);
    vector<int>path;
    int source=8,destination=34;
    
    if(board[destination]<0)
    cout<<"No path possible"<<endl;
    else
    {
        int ans=g.shortestDistance(source,destination,path);
        cout<<"Minimum number of dice Throws required to reach destination "<<destination<<" from source "<<source<<" is "<<ans<<endl;
        cout<<"Their path is : ";
        for(int i=path.size()-1;i>=0;i--)
        cout<<path[i]<<"-->";
    }
    
}
