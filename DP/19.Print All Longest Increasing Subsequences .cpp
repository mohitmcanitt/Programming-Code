/*

Input :- 10,22,42,33,21,50,41,60,80,3
Output:-  10 22 42 50 60 80
           10 22 33 50 60 80
           10 22 33 41 60 80


*/
  
  

#include <bits/stdc++.h>
using namespace std;

class pp{
    public:
    int l;
    int i;
    int val;
    string psf;
    pp(int l,int i,int val,string psf)
    {
        this->l=l;
        this->i=i;
        this->val=val;
        this->psf=psf;
    }
};

void printLis(vector<int>v,vector<int>dp)
{
    int max_length=*max_element(dp.begin(),dp.end());

    queue<pp>q;
    for(int i=0;i<dp.size();i++)
    {
        if(dp[i]==max_length)
        {
            pp obj(dp[i],i,v[i]," "+to_string(v[i]));
            q.push(obj);
        }
            
    }
    while(!q.empty())
    {
        pp temp=q.front();
        q.pop();
        int next_length=temp.l-1;
        int index=temp.i;
        int val=temp.val;
        string s=temp.psf;
        if(next_length==0)
            cout<<s<<endl;
        
     //  cout<<next_length<<" "<<index<<" "<<val<<" "<<s<<endl;
       
        for(int i=0;i<index;i++)
        {
            if(dp[i]==next_length and v[i]<val)
            {
                pp obj(dp[i],i,v[i]," "+to_string(v[i])+s);
                 q.push(obj);
            }
               
        }
    }
}

void lis(vector<int>v)
{
    vector<int>dp(v.size(),1);
    for(int i=1;i<v.size();i++)
    {
        int max_len=0;
        for(int j=i-1;j>=0;j--)
        {
            if(v[i]>v[j])
                max_len=max(max_len,dp[j]);
        }
        dp[i]=1+max_len;
    }
    printLis(v,dp);
}


int main() {
    vector<int>v{10,22,42,33,21,50,41,60,80,3};
    lis(v);
}
