// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1#  
bool isSafeToPlace(int x,int y,int n,vector<vector<int>>&board)
    {
        for(int i=x;i>=0;i--)
        {
            if(board[i][y]==1)
                return false;
        }
        for(int i=x,j=y;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]==1)
                return false;
        }
        for(int i=x,j=y;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]==1)
                return false;
        }
        return true;
    }
    bool solveNqueen(int curr_row,int n,vector<vector<int>>&ans,vector<vector<int>>&board)
    {
        if(curr_row==n)
        {
            vector<int>v;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(board[i][j]==1)
                        v.push_back(j+1);
            ans.push_back(v);            
            return false;            
        }
        
        for(int j=0;j<n;j++)
        {
            if(isSafeToPlace(curr_row,j,n,board))
            {
                board[curr_row][j]=1;
                bool can_able_to_place_in_next_row=solveNqueen(curr_row+1,n,ans,board);
                if(can_able_to_place_in_next_row)
                    return true;
                else
                   board[curr_row][j]=0;
            }
        }
        return false;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
    vector<vector<int>>ans;
    vector<vector<int>>board(n,vector<int>(n,0));
    
    solveNqueen(0,n,ans,board);
    return ans;
    }
