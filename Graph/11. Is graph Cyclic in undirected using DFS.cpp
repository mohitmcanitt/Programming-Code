/*
Refer : https://www.geeksforgeeks.org/detect-cycle-undirected-graph/


*/

#include<bits/stdc++.h>
using namespace std;


    bool dfs(int src,int parent,vector<bool>&visited,vector<int>adj[])
    {
        visited[src]=true;
        for(auto nbhrs:adj[src])
        {
            if(visited[nbhrs]==false)
            {
                bool cycle_mila=dfs(nbhrs,src,visited,adj);
                if(cycle_mila==true)
                    return true;
            }    
            else if(nbhrs!=parent)
                return true;
        }
        return false;
        
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	           {
	               if(dfs(i,-1,visited,adj))
	                   return true;     
	           } 
	    }
	    return false;
	}

int main(){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool ans =isCycle(V, adj);
		if(ans)
			cout << "Contains Cycle\n";
		else cout << "Does not Contains Cycle\n";

	return 0;
    }
