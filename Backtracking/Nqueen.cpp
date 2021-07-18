// Queen Should not placed neither in same column as well as not in left diagonal and right diagonal
/*
5
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0 

*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board,int x,int y,int n)
{
    // upper column
    int i=x;
    while(i>=0)
    {
        if(board[i][y]==1)
            return false;
        i--;    
    }
    // Left Upper Diagonal 

     i=x;
     int j=y;
    while(i>=0 and j>=0)
    {
        if(board[i][j]==1)
            return false;
          i--;
          j--;  
    }
    // Right upper Diagonal
    i=x;
    j=y;
    while(i>=0 and y<n)
    {
        if(board[i][j]==1)
            return false;
        i--;
        j++;    
    }
    return true;
}

bool nqueen(vector<vector<int>>&board,int curr_row,int n)
{
    if(curr_row==n)
    {
        // you have successfully places n queen
        return true;
    }
        
    // Recursive case
    // Try to place queen in current row and call on the remaining part    
    for(int j=0;j<n;j++)
    {
        // we have to check if curr_row,j position is safe to place queen or not
        if(isSafe(board,curr_row,j,n))
        {
            // Place queen -- Assumuing row_curr,j is correct position
            board[curr_row][j]=1;
            // check for next row, next queen rkh paa rhe hai
            bool next_rkh_paa_rhe_hai=nqueen(board,curr_row+1,n);
            if(next_rkh_paa_rhe_hai)
                return true;
        }
        // Means jo maine assumption liya tha ki we are placing queen is correct position
        board[curr_row][j]=0; // backtrack
    }
    return false;

}
int main() {
    int n;
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,0));

    bool solu_exist=nqueen(board,0,n);
    if(solu_exist)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
             cout<<endl;   
        }
    }
    else 
    cout<<"Solution doesn't exist";

}
