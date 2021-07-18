// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>>&board,vector<int>&xMove,vector<int>&yMove,int x,int y,int count)
{
    if(count==64)
      return true;

    for(int i=0;i<8;i++)
    {
        int nextX=x+xMove[i];
        int nextY=y+yMove[i];
        
        if(nextX>=0 and nextX<8 and nextY>=0 and nextY<8 and board[nextX][nextY]==-1)
        {
            board[nextX][nextY]=count;
            if(solve(board,xMove,yMove,nextX,nextY,count+1))
                return true;
            else
                board[nextX][nextY]=-1;    
        }
    }
    return false;
}


int main() {
    vector<vector<int>>board(8,vector<int>(8,-1));
    board[0][0]=0;

    vector<int> xMove = { 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> yMove = { 1, 2, 2, 1, -1, -2, -2, -1 };

    bool soln_exist=solve(board,xMove,yMove,0,0,1);

    if(soln_exist)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                cout<<board[i][j]<<" ";
          cout<<endl;  

        }    
    }
}
