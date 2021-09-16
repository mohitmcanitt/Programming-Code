/*
s="hellolle";
output
h
e
l
ll
l
lol
lloll
ellolle
o
l
ll
l
e


*/
#include<bits/stdc++.h>
using namespace std;

vector<string>solve(string s)
{
    vector<string>ans;
    int start=0;
    int end=0;
    int i=0;

    while(i<s.length())
    {
        string ss="";
        ss+=s[i];
        ans.push_back(ss);
        int low=i;
        int high=i+1;
        // Even Length
        while(low>=0 and high<s.length() and s[low]==s[high])
        {
            ans.push_back(s.substr(low,high-low+1));
            low--;
            high++;
          
        }
        low=i;
        high=i+2;
        // Odd Length
        while(low>=0 and high<s.length() and s[low]==s[high])
        {
            ans.push_back(s.substr(low,high-low+1));
            low--;
            high++;
        }
       i++; 
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    vector<string>ans=solve(s);
    for(auto x:ans)
        cout<<x<<endl;

}
