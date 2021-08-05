 bool helper(int idx,int x,int y,string word,vector<vector<char>>&board)
  {
      if(x<0 or y<0 or x==board.size() or y==board[0].size() or board[x][y]!=word[idx])
          return false;
      if(idx==word.size()-1)
          return true;
      
      char temp=board[x][y];
      board[x][y]='*';
      
      bool move=helper(idx+1,x+1,y,word,board) or 
                helper(idx+1,x-1,y,word,board) or 
                helper(idx+1,x,y-1,word,board) or 
                helper(idx+1,x,y+1,word,board);
     
           board[x][y]=temp; // undo changes from '*' to original
           return move;

  }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(helper(0,i,j,word,board))
                    return true;
        return false;
    }
