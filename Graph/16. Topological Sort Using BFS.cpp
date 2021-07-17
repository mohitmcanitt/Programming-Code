/*
Using BFS:
1. Calculate Indegree of each vertex
2. create a queue 
3. push vertex whose indegree is zero
4. Pop front element
5. decrease indegree of its neighbours by 1
6. If indegree becomes zero by decrementing then push it into queue

Input:
7
8
0 1
0 2
0 3
3 4
1 2
4 6
5 6
2 4

Output:
0 5 1 3 2 4 6
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int v,vector<int>adj[])
{
	// Calculate in degree of each vertex
	vector<int>inDegree(v,0);
	for(int i=0;i<v;i++)
		for(auto x:adj[i])
			inDegree[x]++;
	
	vector<int>ans;
	queue<int>q;
	for(int i=0;i<v;i++)
	{
		if(inDegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		int src=q.front();
		q.pop();
		ans.push_back(src);
		for(auto nbhrs:adj[src])
		{
			inDegree[nbhrs]--;
			if(inDegree[nbhrs]==0)
				q.push(nbhrs);	
		}
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
		int s,d;
		cin>>s>>d;
		adj[s].push_back(d);
	}
	vector<int>linear_ordering=solve(v,adj);
	for(auto x:linear_ordering)
		cout<<x<<" ";
	
}
