// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
// https://www.youtube.com/watch?v=1ZGJzvkcLsA
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
          vector<int>ans;
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        int dir=0;
        while(top<=bottom and left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                    ans.push_back(matrix[top][i]);
                top++;            
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;    
            }
              
            dir=(dir+1)%4;
        }
        return ans;
    }
};
