#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/* iterative method
string itr_helper(string input,int n)
{
    string ans="";
    int i=0;
    while(n>0)
    {
        if(n&1)
            ans+=input[i];
        i++;
        n=n>>1;    
    }
    return ans;
}

void iterative_solve(string input,vector<string>&v)
{
    int n=pow(2,input.length());
    for(int i=1;i<=n-1;i++)
        v.push_back(itr_helper(input,i));
}

*/
// recursive

void recursive_solve(string input,vector<string>&v,string output="")
{
    if(input.length()==0)
    {
        v.push_back(output);
        return;
    }
    recursive_solve(input.substr(1),v,output+input[0]);
    recursive_solve(input.substr(1),v,output);
}


int main() {
    vector<string>v_recu;
    vector<string>v_itr;
    recursive_solve("abc",v_recu);
    iterative_solve("abc",v_itr);

    for(auto x:v_recu)
        cout<<x<<" ";
    cout<<endl;

    for(auto x:v_itr)
        cout<<x<<" ";
    cout<<endl;        

}

// Output 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string itr_helper(string input,int n)
{
    string ans="";
    int i=0;
    while(n>0)
    {
…

}

/*
Output
abc ab ac a bc b c  
a b ab c ac bc abc 
*/
