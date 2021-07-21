/*
Method 1: using graph with o(n^2) time complexity

steps 1: create 2 arrays -- named as indegree and outdegree
steps 2: calculate indegree and outdegree of each vertex.
steps 3: celebrity will who, whose vertex whose outdegree is 0 and indegree is n-1
steps 4: else no celebrity found

GFG : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
*/

int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int indegree[n]={0};
        int outdegree[n]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(i!=j)
                {
                  indegree[j]+=M[i][j];
                  outdegree[i]+=M[i][j];  
                }
                        
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==n-1 and outdegree[i]==0)
                return i;
        }
        return -1;
    }

/*
method 2: using stack with time complexity o(n)
Approach : (a,b)=1 means a knows b , discard a , add b in stack as potetial answer .. 
            a cann't bcoz celebrity is who, who dont know anyone but he is known by everone.
         : (a,b)=0 means a doesn't know b , discard b and add a in stack as potetial candidate..
            b is not known by a , but judge is known by everyone ..
         : Do above until there is only one candidate left
         : check potetial candiate row and column except i==pot
           all row should contains 0 of potential
           all col should contains 1 of potential

*/

int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 and n==1) // n=1 and trust [[]]
            return 1;
        if(trust.size()==0 and n!=1) // n=3 and trust [[]]
            return -1;
        
        
        vector<vector<int>>vect(n,vector<int>(n,0));
        stack<int>st;
        for(int i=0;i<trust.size();i++)
        {
            int x=trust[i][0]-1; // to make 0 based indexing
            int y=trust[i][1]-1;
            vect[x][y]=1;
            st.push(y); // x knows y : means x cann't be potetial judge
        }
        while(st.size()>=2)
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            if(vect[x][y]==1)
                st.push(y);
            else
                st.push(x);
        }
        int pot=st.top();
        for(int i=0;i<n;i++)
        {
            if(i!=pot)
            {
                if(vect[pot][i]==1 or vect[i][pot]==0)
                    return -1;
            }
        }
        return pot+1;
    }
