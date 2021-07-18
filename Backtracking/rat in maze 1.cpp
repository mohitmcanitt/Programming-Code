// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
void solve(vector<vector<int>>&m,vector<string>&ans,vector<vector<bool>>&visited,string output,int x,int y,int n)
    {
        if(x==n-1 and y==n-1)
        {
            ans.push_back(output);
            return;
        }
        // Down
        if(x+1<n and visited[x+1][y]==false and m[x+1][y]==1)
        {
            visited[x][y]=true;
            solve(m,ans,visited,output+'D',x+1,y,n);
            visited[x][y]=false;
        }
        
        // left
         if(y-1>=0 and visited[x][y-1]==false and m[x][y-1]==1)
        {
            visited[x][y]=true;
            solve(m,ans,visited,output+'L',x,y-1,n);
            visited[x][y]=false;
        }
        
        // right
        
        if(y+1<n and visited[x][y+1]==false and m[x][y+1]==1)
        {
            visited[x][y]=true;
            solve(m,ans,visited,output+'R',x,y+1,n);
            visited[x][y]=false;
        }
        
        // up
        if(x-1>=0 and visited[x-1][y]==false and m[x-1][y]==1)
        {
            visited[x][y]=true;
            solve(m,ans,visited,output+'U',x-1,y,n);
            visited[x][y]=false;
        }
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<string>ans;
        
        if(m[0][0])
          solve(m,ans,visited,"",0,0,n);
        return ans;
    }
