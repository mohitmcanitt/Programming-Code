// https://www.youtube.com/watch?v=Zobz9BXpwYE&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=5

// correction needed

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
        if(jumps[i]>0)
        {
            int allowed_jumps=jumps[i];
            int min_moves_for_current_stairs=INT_MAX;
            for(int j=1;j<=allowed_jumps;j++)
            {
                if(i+j<=n and dp[j]!=-1)
                        min_moves_for_current_stairs=min(dp[i+j],min_moves_for_current_stairs);
            }
            if(min_moves_for_current_stairs!=INT_MAX)
            dp[i]=min_moves_for_current_stairs+1;
            else
            dp[i]=-1;
        }
        else
             dp[i]=-1;
     
    }
    for(int i=0;i<n;i++)
        cout<<jumps[i]<<" ";
        cout<<endl;
        for(int i=0;i<=n;i++)
            cout<<dp[i]<<" ";

        cout<<endl;
   cout<<dp[0];

}
