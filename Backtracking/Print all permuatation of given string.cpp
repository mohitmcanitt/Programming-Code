/*
Input
abcd

Output
abcd
abdc
acbd
acdb
adcb
adbc
bacd
badc
bcad
bcda
bdca
bdac
cbad
cbda
cabd
cadb
cdab
cdba
dbca
dbac
dcba
dcab
dacb
dabc
*/

#include <iostream>
using namespace std;

void permute(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.length();i++)
    {
        string s=input;
        swap(s[0],s[i]);
        permute(s.substr(1),output+s[0]);
    }
}

int main() {
    string s;
    cin>>s;
    permute(s,"");
}
