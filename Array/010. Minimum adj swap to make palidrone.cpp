#include<bits/stdc++.h>
using namespace std;

bool isPalindrone(string s)
{
    unordered_map<char,int>um;
    int odd=0;
    for(auto x:s)
        um[x]++;
    for(auto x:um)
        odd+=(x.second%2);
    return odd<=1;    
}

int minSwap(string s)
{
    if(isPalindrone(s)==false)
        return -1;
    int l=0;
    int r=s.length()-1;
    int count=0;
    while(l<r)
    {
        if(s[l]==s[r])
        {
            l++;
            r--;
        }
        else
        {
            int k=r-1;
            while(k>l && s[k]!=s[l])
                k--;
            if(l==k)
            {
                count++;
                swap(s[l],s[l+1]);
            }
            else
            {
                while(k<r)
                {
                    count++;
                    swap(s[k],s[k+1]);
                    k++;
                }
            }
            l++;
            r--;    
         }
    }
    return count;
}

int main() {
    string s="abcd";
    cout<<minSwap(s);
}
