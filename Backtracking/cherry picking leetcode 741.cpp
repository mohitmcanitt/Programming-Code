    int ans=0;
    
    void bottom_to_top(int x,int y,vector<vector<int>>&grid,int cherry_collected)
    {
        if(x<0 or x>=grid.size() or y<0 or y>=grid.size() or grid[x][y]==-1)
            return;
        if(x==0 and y==0)
        {
            ans=max(ans,cherry_collected);
            return;
        }
        
        int cherry=grid[x][y];
        grid[x][y]=0;
        bottom_to_top(x,y-1,grid,cherry_collected+cherry);
        bottom_to_top(x-1,y,grid,cherry_collected+cherry);
        grid[x][y]=cherry;
    }
    
    void top_to_bottom(int x,int y,vector<vector<int>>&grid,int cherry_collected)
    {
        if(x<0 or x>=grid.size() or y<0 or y>=grid.size() or grid[x][y]==-1)
            return;
        if(x==grid.size()-1 and y==grid.size()-1)
        {
            bottom_to_top(x,y,grid,cherry_collected);
            return;    
        }

        int cherry=grid[x][y];
        grid[x][y]=0;
        top_to_bottom(x,y+1,grid,cherry_collected+cherry);
        top_to_bottom(x+1,y,grid,cherry_collected+cherry);
        grid[x][y]=cherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.size()==1)
            ans=grid[0][0];
        top_to_bottom(0,0,grid,0);
        return ans;
    }
