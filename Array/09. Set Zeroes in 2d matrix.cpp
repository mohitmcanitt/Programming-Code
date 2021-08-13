// Method 1: provided element cann't have negative value
// Time O(m*n) * O(m*n)
// Space 0(1)
void solve(vector<vector<int>>&nums,int x,int y)
    {
        int up=x-1;
        while(up>=0)
        {
            if(nums[up][y]!=0)
            nums[up][y]=-1;
            up--;
        }
        int down=x+1;
        while(down<nums.size())
        {
            if(nums[down][y]!=0)
                nums[down][y]=-1;
            down++;
        }
        int left=y-1;
        while(left>=0)
        {
            if(nums[x][left]!=0)
                nums[x][left]=-1;
            left--;
        }
        int right=y+1;
        while(right<nums[0].size())
        {
            if(nums[x][right]!=0)
                nums[x][right]=-1;
            right++;
        }
    }
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==0)
                    solve(matrix,i,j);
         for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==-1)
                    matrix[i][j]=0;
    }

// Method 2:
// Time Complexity : 0(m*n)
// Space Complexity : 0(m+n)

void setZeroes(vector<vector<int>>& matrix) {
        
        int x=matrix.size();
        int y=matrix[0].size();
        
        vector<int>row(x,-1);
        vector<int>col(y,-1);
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                if(row[i]==0 or col[j]==0)
                    matrix[i][j]=0;
    }

// Method 3:
// Time : O(m*n)
// Space : 0(1)
// https://afteracademy.com/blog/set-matrix-zeros

    void setZeroes(vector<vector<int>>& matrix) {
        
        bool firstRow=false;
        bool firstCol=false;
        
        for(int i=0;i<matrix[0].size();i++)
            if(matrix[0][i]==0)
                firstRow=true;
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][0]==0)
                firstCol=true;
        
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
            {
                 if(matrix[i][j]==0)
                 {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                 }
                   
            }
        
         for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
            {
                 if(matrix[0][j]==0 or matrix[i][0]==0)
                 matrix[i][j]=0;
                   
            }
          if(firstRow==true)
               for(int i=0;i<matrix[0].size();i++)
                      matrix[0][i]=0;
         if(firstCol==true)
             for(int i=0;i<matrix.size();i++)
                  matrix[i][0]=0;
            
    }
