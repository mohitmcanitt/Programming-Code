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
