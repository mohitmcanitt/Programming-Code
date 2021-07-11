// https://www.youtube.com/watch?v=Lj68VJ1wu84&t=15s
// https://leetcode.com/problems/ugly-number-ii/
int nthUglyNumber(int n) {
        vector<int>v;
        v.push_back(1);
        int p_2=0;
        int p_3=0;
        int p_5=0;
        while(v.size()!=n)
        {
            int p_2_nxtVal=v[p_2]*2;
            int p_3_nxtVal=v[p_3]*3;
            int p_5_nxtVal=v[p_5]*5;
            
            int next_input=min(p_2_nxtVal,min(p_3_nxtVal,p_5_nxtVal));
            v.push_back(next_input);
            
            if(next_input==p_2_nxtVal)
                p_2++;
            if(next_input==p_3_nxtVal)
                p_3++;
            if(next_input==p_5_nxtVal)
                p_5++;
        }
        return v[n-1];
   }

