/*
Cycle detection using BFS

 For every visited vertex ‘v’,
  if there is an adjacent ‘u’ 
  such that u is already visited 
  and u is not a parent of v,
   then there is a cycle in the graph. 
   If we don’t find such an adjacent for any vertex, 
   we say that there is no cycle.


Refer : https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/
4 vertices and 3 edges
4 3
0 1
1 2
2 3
 doesn't contains cycle;
 
 4 vertices and 3 edges
4 3
1 2
2 3
3 1
contains cycle;
 
*/

#include<bits/stdc++.h>
using namespace std;

	bool isCycle(int v, vector<int>adj[])
	{
	    int par[v];
        bool visited[v]={false};
        
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                par[i]=-1;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int temp=q.front();
                    q.pop();
                    for(auto nbhrs:adj[temp])
                    {
                        if(visited[nbhrs]==false)
                        {
                            q.push(nbhrs);
                            visited[nbhrs]=true;
                            par[nbhrs]=temp;
                        }
                        else if(visited[nbhrs]==true and par[temp]!=nbhrs)
                             return true;
                    }
                }
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
		bool ans = isCycle(V, adj);
		if(ans)
			cout << "Contains";
		else cout << "Not contains";
    	return 0;
    }    
