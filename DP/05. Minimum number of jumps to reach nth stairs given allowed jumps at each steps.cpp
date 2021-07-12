// 0 is not included in jumps
// 6
// 2 4 1 2 2 3
// Output 3
// dp : 3 4 1 2 2 3



#include <iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cin>>n;
    int jumps[n];
    for(int i=0;i<n;i++)
        cin>>jumps[i];
    int dp[n+1];
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        int minimum_for_curr_steps=INT_MAX;
        for(int j=1;j<=jumps[i]&&i+j<=n;j++)
            minimum_for_curr_steps=min(dp[i+j],minimum_for_curr_steps);
        dp[i]=minimum_for_curr_steps+1;
    } 
    cout<<dp[0];   
}
