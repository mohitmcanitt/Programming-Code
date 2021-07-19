// BFS will help us to get minimum steps to reach any cell from given cell


int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    // Zero based index
	    
	    int x_pos=KnightPos[0]-1;
	    int y_pos=KnightPos[1]-1;
	    int x_tar=TargetPos[0]-1;
	    int y_tar=TargetPos[1]-1;
	    
	    vector<int> xMove = { 2, 1, -1, -2, -2, -1, 1, 2 };
        vector<int> yMove = { 1, 2, 2, 1, -1, -2, -2, -1 };
	    
	    if(x_pos==x_tar and y_pos==y_tar)
            return 0;
            
        vector<vector<int>>dist(N,vector<int>(N,0));
        queue<pair<int,int>>q;
        q.push({x_pos,y_pos});
        
        while(!q.empty())
        {
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int nextX=x+xMove[i];
                int nextY=y+yMove[i];
                
                if(nextX>=0 and nextX<N and nextY>=0 and nextY<N and dist[nextX][nextY]==0)
                {
                    dist[nextX][nextY]=dist[x][y]+1;
                    q.push({nextX,nextY});
                }
            }
        }
        return dist[x_tar][y_tar];
	}
