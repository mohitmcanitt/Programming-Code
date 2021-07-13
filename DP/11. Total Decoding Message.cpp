// leetcode 91

#include<bits/stdc++.h>
using namespace std;

int countWays(string s)
{
    if(s[0]=='0')
        return 0;
    int n=s.length();
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='0' and s[i]=='0')
            dp[i]=0;
        else if(s[i-1]=='0' and s[i]!='0')
            dp[i]=dp[i-1];
        else if(s[i-1]!='0' and s[i]=='0')        
        {
            if(s[i-1]=='1' or s[i-1]=='2')
                dp[i]=i>=2?dp[i-2]:1;
             else 
             dp[i]=0;   

        }
        else
        {
            int x=s[i-1]-'0';
            int y=s[i]-'0';
            int num=x*10+y;
            if(num<=26)
                dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
             else
             dp[i]=dp[i-1];   
        }
    } 
    return dp[n-1];
}


int main()
{
    string s;
    cin>>s;
    cout<<countWays(s);
}
