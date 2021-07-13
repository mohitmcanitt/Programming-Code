/* 
you are given a number n.
you are required to count number of binary string in which there is no consecutive 0's

for n->3
010,110,101,110,111
*/

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int dp0=1;
    int dp1=1;
    for(int i=2;i<=n;i++)
    {
        int temp=dp1;
        dp1=dp0+dp1;
        dp0=temp;
    }
    cout<<dp0+dp1;
}
