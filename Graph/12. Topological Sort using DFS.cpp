/*
Refer : https://www.geeksforgeeks.org/topological-sorting/

Few important applications of topological sort are-

Scheduling jobs from the given dependencies among jobs
Instruction Scheduling
Determining the order of compilation tasks to perform in makefiles
Data Serialization

USING DFS:

steps 1: start with source src node
steps 2: go to its depth until node doest have nbhrs
steps 3: before returning push_front in list that node 

INPUT
https://www.gatevidyalay.com/topological-sort-topological-sorting/

OUTPUT
1-->2,3,
2-->5,4,
3-->4,6,
4-->6,5,
Topological sort of given graph 
1->3->2->4->6->5->

*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>adjList;
    public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
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

    void helper(int src,map<int,bool>&visited,list<int>&ans)
    {
        visited[src]=true;
        for(auto nbhrs:adjList[src])
        {
            if(visited[nbhrs]==false)
                helper(nbhrs,visited,ans);
        }
        ans.push_front(src);
        return;
    

    }

    list<int> topological_sort(int src)
    {
        map<int,bool>visited;
        list<int>ans;
        for(auto node:adjList)
        {
            if(visited[node.first]==false)
            {
                helper(node.first,visited,ans);
            }
        }
        return ans;
    }
};


int main() {
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.addEdge(2,4);
    

    g.printEdge();
    cout<<"Topological sort of given graph \n";
    list<int>ans=g.topological_sort(1);
    for(auto x:ans)
        cout<<x<<"->";
}
