// Only horizontal and vertical

void solve(pair<int,int>src,map<pair<int,int>,bool>&visited,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            if(i-1>=0 and grid[i-1][j]=='1' and visited[make_pair(i-1,j)]==false)  
            {
                q.push(make_pair(i-1,j));
                visited[make_pair(i-1,j)]=true;
            }
                 
            if(i+1<grid.size() and grid[i+1][j]=='1' and visited[make_pair(i+1,j)]==false)
            {
                q.push(make_pair(i+1,j));
                visited[make_pair(i+1,j)]=true;
            }
                
            if(j-1>=0 and grid[i][j-1]=='1' and visited[make_pair(i,j-1)]==false)
            {
                q.push(make_pair(i,j-1));
                visited[make_pair(i,j-1)]=true;
            }
                
            if(j+1<grid[0].size() and grid[i][j+1]=='1' and visited[make_pair(i,j+1)]==false)
            {
                  q.push(make_pair(i,j+1));
                visited[make_pair(i,j+1)]=true;
            }
              
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        map<pair<int,int>,bool>visited;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                visited.insert(make_pair(make_pair(i,j),false));
        
        int count=0;
        
        for(auto x:visited)
        {
            if(x.second==false and grid[x.first.first][x.first.second]=='1')
            {
                count++;
                solve(x.first,visited,grid);
                for(auto x:visited)
            cout<<x.second<<" ";
                cout<<endl;
            }
        }
        
        return count;
    }
