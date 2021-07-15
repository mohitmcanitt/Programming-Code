/*
Input:

A B 
A S 
S C 
C D 
S G 
G F 
C E 
C F 
E H 
G H

DFS, If source is C
OUTPUT:
C S A B G F H E D 


Graph example taken from below link
https://www.youtube.com/watch?v=stRst6p9s8NVg

Adjlist :

A-->B,S,
B-->A,
C-->S,D,E,F,
D-->C,
E-->C,H,
F-->G,C,
G-->S,F,H,
H-->E,G,
S-->A,C,G,



*/


#include <bits/stdc++.h>
using namespace std;

void dfs_helper(map<char,vector<char>>adjList, char src, map<char,bool>&visited)
{
	visited[src]=true;
	cout<<src<<" ";
	for(auto x:adjList[src])
		{
			if(visited[x]==false)
				dfs_helper(adjList,x,visited);
		}

}

void dfs(map<char,vector<char>>adjList,char src)
{
	map<char,bool>visited;
	for(auto x:adjList)
		visited[x.first]=false;
	dfs_helper(adjList,src,visited);	
}

int main() {

    map<char,vector<char>>adjList;
    int no_of_edges=10;
    while(no_of_edges)
    {
        char u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        no_of_edges--;
    }
    dfs(adjList,'C');
}

