/*
Input:

5
6
0 1
0 4
1 2
3 4
1 3
2 3

Output:

0-> 1->4->
1-> 2->3->
2-> 3->
3-> 4->
4-> 

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int v;
    int e;
    cin>>v>>e;
    vector<int>adj[v]; // v number of vectors
    while(e--)
    {
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<"-> ";
        for(auto x:adj[i])
            cout<<x<<"->";
         cout<<endl;   
    }
}
