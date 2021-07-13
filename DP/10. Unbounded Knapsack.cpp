/*
4
1 3 4 5
10 40 50 70
8

output: 110



*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>wt,vector<int>val,int capacity)
{
    int n=wt.size();
    int dp[capacity+1];
    dp[0]=0;
    for(int i=1;i<=capacity;i++)
    {
        int curr_max=INT_MIN;
        for(int j=0;j<n;j++)
        {
            if(wt[j]<=i)
                curr_max=max(curr_max,dp[i-wt[j]]+val[j]);
        }
        if(curr_max==INT_MIN)
            curr_max=0;
        dp[i]=curr_max;
    }

    for(int i=0;i<=capacity;i++)
        cout<<dp[i]<<" ";
        cout<<endl;
 return dp[capacity];

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
