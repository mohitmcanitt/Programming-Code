/*
There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.

output :
{ { 14, 2, 11 },
  {11, 14, 5 },
  {14, 3, 10 } }

input : 10
*/


int Solution(vector<vector<int> > &A) {
    vector<vector<int>>dp;
    dp=A;
    int n=A.size();
    for(int i=1;i<A.size();i++)
    {
        dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]+=min(dp[i-1][0],dp[i-1][1]);
    }
    return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));

}
