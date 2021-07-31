/*
{
{10,15,20,30},
{2,5,8,14,24},
{0,11,30,90}
}

Output: 0 2 5 8 10 11 14 15 20 24 30 30 90
*/
#include<bits/stdc++.h>
using namespace std;
class helper{
    public:

    int val;
    int aPos; // Array Position
    int iPos; // index position
    
    helper(int val,int aPos,int iPos)
    {
        this->val=val;
        this->aPos=aPos;
        this->iPos=iPos;
    }
};
class compare{
    public:
    bool operator()(helper h1,helper h2)
    {
        return h1.val>h2.val; // min heap
    }
};

vector<int> mergeKArrays(vector<vector<int> > arr){
    
    //Complete this function
        priority_queue<helper,vector<helper>,compare>pq;

        for(int i=0;i<arr.size();i++)
        {
            helper h(arr[i][0],i,0);
            pq.push(h);
        }
                
        vector<int>ans;
        while(!pq.empty())
        {
            helper obj=pq.top();
            pq.pop();
            ans.push_back(obj.val);
            if(obj.iPos==(arr[obj.aPos].size())-1)
                continue;
            else
                {
                    helper h(arr[obj.aPos][obj.iPos+1],obj.aPos,obj.iPos+1);
                    pq.push(h);
                }    
        }
         return ans;    
    
    
}
