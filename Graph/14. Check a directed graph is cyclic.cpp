/*
Approach:

we maintain a visited array to track which is visited
as well maintain a call stack which store the path

steps : 
1. Mark source vertex as visited and add source in our call stack
2. now visit its nbhrs in dfs manner
3. if nbhrs is not visited .. then call dfs again
        and store its return value if, it return true , then cycle mila
        other wise visited another vertex
   if nbhrs is visited .. then check in our call stack
        if vertex is in call stack --> return true means cycle mila
        else visit next vertex
4. all nodes of src is visited , now pop src from call stack

Note : for finding an element in call stack will take mouch time
    so. we will make a call stack array and intialize with false.
    If any vertex is in the path then mark call stack vertex index as visited

    If any vertex is popping out which means mark is false;

7 8  --> seven vertex(0..7) and 8 edges
0 1
1 2
1 5
2 3
3 4
4 2
4 5
5 6

Output : contains cycle


*/

#include<bits/stdc++.h>
using namespace std;

bool dfs_helper(int src,vector<bool>&visited,vector<bool>&callStack,vector<int>adj[])
{
    visited[src]=true;
    callStack[src]=true;
    for(auto nbhrs:adj[src])
     {
         if(visited[nbhrs]==false)
         {
             bool cycle_mila=dfs_helper(nbhrs,visited,callStack,adj);
             if(cycle_mila==true)
                return true;
         }
         else if(callStack[nbhrs])  // agar vertex visited hai and call stack mai v hai then, cycle mila
            return true;

     }   
     callStack[src]=false; // meaning popping out from call stack
     return false;
}


bool isCyclic(int v,vector<int>adj[])
{
    vector<bool>visited(v,false);
    vector<bool>callStack(v,false);
    for(int i=0;i<v;i++)
     {
         if(visited[i]==false)
            {
                if(dfs_helper(i,visited,callStack,adj))
                        return true;
            }
     }  
    return false;
}


int main() {
   int v,e;
   cin>>v>>e;
   vector<int>adj[v];

    int esave=e;
   while(e--)
   {
       int s,d;
       cin>>s>>d;
       adj[s].push_back(d);
   }
 
    if(isCyclic(v,adj))
    cout<<"Contains Cycle";
    else
    cout<<"Doesn't Contains Cycle";
}
