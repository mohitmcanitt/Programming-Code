/*
Topological sorting is used to resolve dependency order.
Its provides linear ordering

Note : Topological sorting should be implemented only on Directed Acyclic Graph.
       So, before topological sorting , we must ensure its acyclic graph.
       
Steps 1: Call DFS with Source
Steps 2: Visit Its Neighbour 
Steps 3: Once all neighbours is visited, so before returning , add(front of list) src in our answer.
    
Solve leetcode question number
207 : https://leetcode.com/problems/course-schedule/
210 : https://leetcode.com/problems/course-schedule-ii/
Input:
4
0 1
0 2
1 3
2 3

Output:
1 3 2 4
1 2 3 4
  
*/

#include<bits/stdc++.h>
using namespace std;

void topo(int src,vector<bool>&visited,vector<int>adj[],list<int>&ans)
{
	visited[src]=true;
	for(auto nbhrs:adj[src])
		{
			if(visited[nbhrs]==false)
				topo(nbhrs,visited,adj,ans);
		}
	ans.push_front(src);	
}


list<int> solve(int v,vector<int>adj[])
{
	vector<bool>visited(v,false);
	list<int>ans;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			topo(i,visited,adj,ans);
	}
	return ans;
}

int main()
{
	int v,e;
	cin>>v>>e;
	vector<int>adj[v];
	while(e--)
	{
		int s,v;
		cin>>s>>v;
		adj[s].push_back(v);
	}
	list<int>ordering=solve(v,adj);
	for(auto x:ordering)
		cout<<x<<" ";
}
