class Solution {
public:

    void fill_row_with_zeroes(int &x,vector<vector<int>>&matrix){
        //row
        for(int i=0;i<matrix[0].size();i++){
          matrix[x][i]=0;
        }
    }

    void fill_col_with_zeroes(int &x,vector<vector<int>>&matrix){
        //col
        for(int i=0;i<matrix.size();i++){
          matrix[i][x]=0;
        }
    }
  // start from here
  // https://takeuforward.org/data-structure/set-matrix-zero/
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>row_arr(row);
        vector<int>col_arr(col);

        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
            if(matrix[i][j]==0){
              row_arr[i]=1;
              col_arr[j]=1;
            }        
          }
        }
        for(int i=0;i<row_arr.size();i++){
             if(row_arr[i]==1)
               fill_row_with_zeroes(i,matrix);
         }
         for(int i=0;i<col_arr.size();i++){
             if(col_arr[i]==1)
               fill_col_with_zeroes(i,matrix);
         }
    }
};