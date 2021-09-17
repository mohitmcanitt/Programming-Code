class Solution {
public:
    int possible=0;
    int dp[51][51][51][51];
    int cp(int r1,int c1,int r2,int c2,vector<vector<int>>&grid)
    {
        if(r1>=grid.size() or r2>=grid.size() or c1>=grid.size() or c2>=grid.size() or grid[r1][c1]==-1 or grid[r2][c2]==-1)
            return INT_MIN;
        if(r1==grid.size()-1 and c1==grid.size()-1)
            return grid[r1][c1];
         if( dp[r1][c1][r2][c2])
             return  dp[r1][c1][r2][c2];
        int cherry=0;
        if(r1==r2 and c1==c2)
            cherry+=grid[r1][c1];
        else
            cherry+=grid[r1][c1]+grid[r2][c2];
        
        
        int f1=cp(r1,c1+1,r2,c2+1,grid);// hh
        int f2=cp(r1,c1+1,r2+1,c2,grid);// hv
        int f3=cp(r1+1,c1,r2+1,c2,grid);// vv
        int f4=cp(r1+1,c1,r2,c2+1,grid);// vh
        cherry+=max(max(f1,f2),max(f3,f4));
        dp[r1][c1][r2][c2]=cherry;
        return cherry;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int ans=cp(0,0,0,0,grid);
        if(ans<0)
            return 0;
       return ans;
    }
};
