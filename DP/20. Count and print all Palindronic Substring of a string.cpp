/*

Input : abbaeae
Output 
Total Number of Palindronic Substring of abbaeae 4
These substrings are 
abba
bb
aea
eae

*/
  
  
  


#include <bits/stdc++.h>
using namespace std;

pair<int,vector<string>> solve(string s)
{
    int n=s.length();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    int count=0;

    // Make diagonal Cell True bcoz its single length palidrone
    for(int i=0;i<n;i++)
        dp[i][i]=true;
   
   // For substring having length 2
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
             dp[i][i+1]=true;
    }   

    for(int i=2;i<n;i++) 
    {
        int k=0;
        for(int j=i;j<n;j++)
        {
            if(s[k]==s[j]) // if extremes character are same then check its diagonal left down
                dp[k][j]=dp[k+1][j-1];
            else
                dp[k][j]=false; // if exremes character are not same then current substring cann't be palidrone
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1 and i!=j)
                    count++;

            }
    }
    vector<string>all_palidrone_substrings;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(dp[i][j]==true and i!=j)
              all_palidrone_substrings.push_back(s.substr(i,j-i+1));
        }
    }    
    return make_pair(count,all_palidrone_substrings);;
}


int main() {
    string s;
    cin>>s;
    pair<int,vector<string>> res=solve(s);
    
    cout<<"Total Number of Palindronic Substring of "<<s<<" "<<res.first;
    cout<<"\nThese substrings are \n";
    for(auto x:res.second)
        cout<<x<<endl;
}
