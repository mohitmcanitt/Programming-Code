/*
Refer : https://www.geeksforgeeks.org/topological-sorting/

Few important applications of topological sort are-

Scheduling jobs from the given dependencies among jobs
Instruction Scheduling
Determining the order of compilation tasks to perform in makefiles
Data Serialization

USING BFS:

steps 1: calculate indegree of each node
steps 2: push node only whose indegree is zero
steps 3: pop node , decrement its nbhrs degree by -1 
    and check it any node having indegree 0 then only push into queue
steps 4: repeat 3-4 until queue is not empty.    

INPUT
https://www.gatevidyalay.com/topological-sort-topological-sorting/

OUTPUT
1-->2,3,
2-->5,4,
3-->4,6,
4-->6,5,
Topological sort of given graph 
1->2->3->4->6->5->

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

    list<int> topological_sort(int src)
    {
        map<int,int>indegree;
        list<int>ans;
        // Calculate indegree of each node
        for(auto node:adjList)
                indegree[node.first]=0;  
         for(auto x:adjList)
         {
              for(auto nbhrs:x.second)
                indegree[nbhrs]++;
         }
                       
        // Push node whose indegree is 0
        queue<int>q;
        for(auto x:indegree)
        {
            if(x.second==0)
                q.push(x.first);
        } 

        while(!q.empty())
        {
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto v:adjList[u]) // decrement indegree of its nbhrs by 1
                indegree[v]--;
                                 
        // Push node from adjList of u whose indegree is 0
            for(auto v:adjList[u])
            {
                if(indegree[v]==0)
                    q.push(v);
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
