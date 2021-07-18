
/*
Input: 

6 0 0 0 0 3 0 0 0
0 0 2 0 4 0 1 7 0
0 0 0 0 2 9 8 0 3
4 6 0 0 0 0 9 3 0
0 0 0 0 1 0 0 0 7
0 7 3 0 0 4 0 0 0 
0 3 8 4 0 2 5 1 9
9 0 0 8 0 1 0 0 0
1 2 6 7 0 5 3 0 4

Output:

6 8 4 1 7 3 2 9 5 
3 9 2 5 4 8 1 7 6 
5 1 7 6 2 9 8 4 3 
4 6 1 2 5 7 9 3 8 
8 5 9 3 1 6 4 2 7 
2 7 3 9 8 4 6 5 1 
7 3 8 4 6 2 5 1 9 
9 4 5 8 3 1 7 6 2 
1 2 6 7 9 5 3 8 4 

*/

#include<bits/stdc++.h>
using namespace std;
// Check this potential number is suitable to fill or not 
bool canWePlace(int board[9][9],int num,int x,int y)
{
    // checking in cuurent row and column

    for(int i=0;i<9;i++)
        if(board[x][i]==num or board[i][y]==num)
            return false;

    // Checking into sub grid

    // Subgrid (x/sqrt(n))*sqrt(n);

    int sx=(x/3)*3;
    int sy=(y/3)*3;

    for(int i=sx;i<sx+3;i++)
    {
        for(int j=sy;j<sy+3;j++)
            if(board[i][j]==num)
            return false;
    }        
    return true;
}

bool solve(int board[9][9],int i,int j)
{
   cout<<count<<endl;
    if(i==9)
        return true;
  
    // if we are last cell of current row. Move to next grid
    if(j==9)
       return solve(board,i+1,0);

    // agar blank nhi hai too skip   

    if(board[i][j]!=0) 
        return solve(board,i,j+1);

    // Recursive case

    for(int number=1;number<=9;number++)
    {
        if(canWePlace(board,number,i,j))
         {
             board[i][j]=number;
             bool couldWeSolve=solve(board,i,j+1);
             if(couldWeSolve)
                return true;
         }   
    }    
    board[i][j]=0 ; // backtrack as we have tried all possible number from 1 to 9.
    return false;

}

int main() {
    int board[9][9];

    for(int i=0;i<9;i++)        
        for(int j=0;j<9;j++)
            cin>>board[i][j];

    bool solu_exists=solve(board,0,0);
    if(solu_exists)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;    
        }
    }
    else
    cout<<"Solution doesn't exist for cuurent suduko";
    
}
