/*
Leetcode : https://leetcode.com/problems/number-of-islands/

NOTE : Declaring array as int grid[row][col] will create problem while pass in function
Input:
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Output:
No of islands 3

*/


/* 
// Optimized with constant space
Instead having a visiting array
we will mark visited grid as grid[x][y]='0';  line number 30


void dfs(vector<vector<char>> &grid,int x,int y,int row,int col)
    {
        
         if (x < 0 || x == row || y < 0 || y == col || grid[x][y] == '0') 
            return;
          grid[x][y]='0';    
        // UP
             dfs(grid,x-1,y,row,col);
        // DOWN
            dfs(grid,x+1,y,row,col);
        // LEFT
            dfs(grid,x,y-1,row,col);
        // Right 
            dfs(grid,x,y+1,row,col);    
            
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        int no_of_islands=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,row,col);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }

*/




#include <bits/stdc++.h>
using namespace std;

void dfs(char **grid,bool **visited,int x,int y,int row,int col)
{
    visited[x][y]=true;
    // UP
    if(x-1>=0 and grid[x-1][y]=='1' and visited[x-1][y]==false)
        dfs(grid,visited,x-1,y,row,col);
    // DOWN
    if(x+1<row and grid[x+1][y]=='1' and visited[x+1][y]==false)
        dfs(grid,visited,x+1,y,row,col);
    // LEFT
    if(y-1>=0 and grid[x][y-1]=='1' and visited[x][y-1]==false)
        dfs(grid,visited,x,y-1,row,col);
    // Right 
    if(y+1<col and grid[x][y+1]=='1' and visited[x][y+1]==false)
        dfs(grid,visited,x,y+1,row,col);           
}

int main() {
    int row;
    int col;
    cin>>row>>col;

    char **grid=new char*[row];
    for(int i=0;i<row;i++)
        grid[i]=new char[col];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>grid[i][j];    

    bool **visited=new bool*[row];
    for(int i=0;i<row;i++)
        visited[i]=new bool[col];    

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            visited[i][j]=false;

   int no_of_island=0;
   for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='1' and visited[i][j]==false)
                {
                    no_of_island++;
                    dfs(grid,visited,i,j,row,col);
                }
        }
    } 
   cout<<"No of islands "<<no_of_island;
}
