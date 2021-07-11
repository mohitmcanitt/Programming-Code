// https://www.youtube.chttps://github.com/mohitmcanitt/Programming-Code/tree/main/Backtrackingom/watch?v=uNqoQ0sNZCM&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=3

#include <iostream>
using namespace std;

int main() {
   int n;
   cin>>n;
   int jumps[n];
   for(int i=0;i<n;i++)
    cin>>jumps[i];

    int dp[n+1];
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        int allowed_jumps=jumps[i];
        int no_of_jumps=0;
        for(int j=1;j<=allowed_jumps;j++)
        {
            if(j+i<=n)
                no_of_jumps+=dp[j+i];
        }
        dp[i]=no_of_jumps;
    }
   cout<<dp[0];
