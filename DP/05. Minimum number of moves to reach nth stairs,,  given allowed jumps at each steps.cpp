// 0 is not included in jumps
// 6
// input : 10
// jumps array : 3 3 0 2 1 2 4 2 0 0
// dp array : 4 4 -1 3 3 2 1 -1 -1 -1 0
// output: 4 minimum four jumps required to reach top stairs
// if jumps allowed from any stairs is 0 assigned -1 in dp array



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
        if(jumps[i]==0)
                dp[i]=-1;
        else
        {
            int minimum_for_curr_steps=INT_MAX;
            for(int j=1;j<=jumps[i]&&i+j<=n;j++)
            {
                if(dp[i+j]!=-1)
                minimum_for_curr_steps=min(dp[i+j],minimum_for_curr_steps);
            }      
            if(minimum_for_curr_steps==INT_MAX)
                dp[i]=-1;
             else       
             dp[i]=minimum_for_curr_steps+1;
        }    
       
    } 
    if(dp[0]==-1)
        cout<<"Cann't reach top Stairs";
    else
        cout<<dp[0];
}
