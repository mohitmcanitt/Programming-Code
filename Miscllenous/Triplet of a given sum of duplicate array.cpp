/*
Triplet Sum in duplicate array
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20

Leetcode : https://leetcode.com/problems/3sum-with-multiplicity/
leetcode number 923

For approach refer editorial of leetcode problem 923
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>v,int target)
{
    sort(v.begin(),v.end());
    int ans=0;
    int M=1000000007;
    for(int i=0;i<v.size()-2;i++)
    {
        int new_target=target-v[i];
        int l=i+1;
        int r=v.size()-1;
        while(l<r)
        {
            int sum=v[l]+v[r];
            if(sum>new_target)
                r--;
            else if(sum<new_target)
                l++;
            else if(v[l]!=v[r])
            {
                int left=1,right=1;
                while(l+1<r and v[l]==v[l+1])
                {
                    left++;
                    l++;
                }
                while(r-1>l and v[r]==v[r-1])
                {
                    right++;
                    r--;
                }
                ans+=(left*right);
                ans%=M;
                l++;
                r--;
            }    
            else{
                int size=r-l+1;
                ans+=((size*(size-1))/2);
                ans%=M;
                break;
            }
        }
       
    }
     return ans;
}


int main() {
    vector<int>v={1,1,2,2,3,3,4,4,5,5};
    int target=8;
    cout<<solve(v,target);
}
