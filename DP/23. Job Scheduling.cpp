// Time Complexity 0(n^2)
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/

#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>v1,vector<int>v2)
{
    return v1[1]<v2[1];
}

int solve(vector<int>&start,vector<int>&end,vector<int>&profit)
{
   int n=start.size();
   vector<vector<int>>v;
   for(int i=0;i<n;i++)
        v.push_back({start[i],end[i],profit[i]});
   
   sort(v.begin(),v.end(),cmp);

   vector<int>dp(n);
   dp[0]=v[0][2];
   for(int i=1;i<n;i++)
   {
       int inc=v[i][2];
       int non_overlapping=-1;
       for(int j=i-1;j>=0;j--)
       {
           if(v[j][1]<=v[i][0])
           {
               non_overlapping=j;
               break;
           }
       }
       if(non_overlapping!=-1)
            inc+=dp[non_overlapping];
       dp[i]=max(inc,dp[i-1]);     
   }     
   return dp[n-1];
}

int main() {
    int n;
    cin>>n;

    vector<int>start(n);
    vector<int>end(n);
    vector<int>profit(n);

    for(int i=0;i<n;i++)
        cin>>start[i];
    for(int i=0;i<n;i++)
        cin>>end[i];
    for(int i=0;i<n;i++)
        cin>>profit[i];

    cout<<"Maximum profit is "<<solve(start,end,profit);            
}
// Time Complexity O(nlogn)
#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>v1,vector<int>v2)
{
    return v1[1]<v2[1];
}

int solve(vector<int>&start,vector<int>&end,vector<int>&profit)
{
   int n=start.size();
   vector<vector<int>>v;
   for(int i=0;i<n;i++)
        v.push_back({start[i],end[i],profit[i]});
   
   sort(v.begin(),v.end(),cmp);

   int dp[n];
   dp[0]=v[0][2];

   for(int i=1;i<n;i++)
   {
       int inc=v[i][2];
       int non_overlapping=-1;
       int low=0;
       int high=i-1;
       while(low<=high)  // just used binary search for finding non overlapping time
       {
           int mid=(low+high)/2;
           if(v[mid][1]<=v[i][0])
           {
               non_overlapping=mid;
               low=mid+1;
           }
           else
                 high=mid-1;
       }
           
       if(non_overlapping!=-1)
            inc+=dp[non_overlapping];
       dp[i]=max(inc,dp[i-1]);     
   }     
   return dp[n-1];
}

int main() {
    int n;
    cin>>n;

    vector<int>start(n);
    vector<int>end(n);
    vector<int>profit(n);

    for(int i=0;i<n;i++)
        cin>>start[i];
    for(int i=0;i<n;i++)
        cin>>end[i];
    for(int i=0;i<n;i++)
        cin>>profit[i];

    cout<<"Maximum profit is "<<solve(start,end,profit);            
}

