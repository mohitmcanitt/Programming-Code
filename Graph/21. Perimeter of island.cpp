// https://leetcode.com/problems/island-perimeter/  leetcode 463


int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
       vector<vector<bool>>visited(row,vector<bool>(col,false));
       vector<vector<int>>dist(row,vector<int>(col,0));
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(visited[i][j]==false and grid[i][j]==1)
                {
                    visited[i][j]=true;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                   
                    while(!q.empty())
                    {
                        auto it=q.front();
                        int x=it.first;
                        int y=it.second;
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int X=x+dx[i];
                            int Y=y+dy[i];
                            
                            if(X>=0 and X<row and Y>=0 and Y<col and grid[X][Y]==0)
                                dist[x][y]+=1;
                            
                            if(X<0 or X==row or Y<0 or Y==col) // add 1 in current cell if there is water
                                dist[x][y]+=1;
                                
                            else if(X>=0 and X<row and Y>=0 and Y<col and visited[X][Y]==false and grid[X][Y]==1)
                            { 
                                visited[X][Y]=true;
                                q.push({X,Y});
                            }
                                
                        }
                    }
                }
            }        
        int perimeter=0;
        for(int i=0;i<row;i++)
              for(int j=0;j<col;j++)
                      perimeter+=dist[i][j];
        
        return perimeter;
    }
