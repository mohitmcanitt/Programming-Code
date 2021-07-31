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


    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<helper,vector<helper>,compare>pq;

        for(int i=0;i<K;i++)
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
            if(obj.iPos==K-1)
                continue;
            else
                {
                    helper h(arr[obj.aPos][obj.iPos+1],obj.aPos,obj.iPos+1);
                    pq.push(h);
                }    
        }
         return ans;
    }
