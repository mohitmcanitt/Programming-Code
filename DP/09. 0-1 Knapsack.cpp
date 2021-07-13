/*
6
wt-->1 2 3 8 7 4
value--> 20 5 10 40 15 25
10

Output:60
dp array
0 0  0  0  0  0  0  0  0  0  0 
0 20 20 20 20 20 20 20 20 20 20 
0 20 20 25 25 25 25 25 25 25 25 
0 20 20 25 30 30 35 35 35 35 35 
0 20 20 25 30 30 35 35 40 60 60 
0 20 20 25 30 30 35 35 40 60 60 
0 20 20 25 30 45 45 50 55 60 60 

*/
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>wt,vector<int>val,int capacity)
{
    int n=wt.size();
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++)
    {
        int curr_weight=wt[i-1]; // ball
        int curr_val=val[i-1];  // runs
        for(int j=0;j<=capacity;j++)
        {
            if(i==0 or j==0)
                dp[i][j]=0;
            else
            {
                if(curr_weight>j)  // if there is lesser ball to play than total ball remaining.. if capacity of current bats is 2-15 but 1 ball only availbe. so he will not play. answer of this will dp[i-1][j];
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],curr_val+dp[i-1][j-curr_weight]);
            }    

        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
    }
    return dp[n][capacity];
}

int main()
{
    int n;
    cin>>n;
    vector<int>wt(n);
    vector<int>val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int capacity;
    cin>>capacity;
    cout<<knapsack(wt,val,capacity);        
}
