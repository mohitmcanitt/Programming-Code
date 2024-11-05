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

#include <iostream>
#include <vector>

using namespace std;

int findCelebrity(vector<vector<int>> &vec)
{
  int row = vec.size();
  int col = vec[0].size();

  stack<int> st;
  for (int i = 0; i < row; i++)
  {
    st.push(i);
  }
  while (st.size() > 1)
  {
    int Person_A = st.top();
    st.pop();
    int Person_B = st.top();
    st.pop();

    if (vec[Person_A][Person_B] == 1)
    {
      st.push(Person_B);
    }
    else
    {
      st.push(Person_A);
    }
  }

  // Step 3: Verify if the last person is a celebrity
  if (st.empty())
    return -1; // No celebrity found
  int potentialCelebrity = st.top();

  // Check if potentialCelebrity knows no one and is known by everyone
  for (int i = 0; i < row; i++)
  {
    if (i != potentialCelebrity)
    {
      // A celebrity should not know anyone
      if (vec[potentialCelebrity][i] == 1)
        return -1;
      // Everyone else should know the celebrity
      if (vec[i][potentialCelebrity] == 0)
        return -1;
    }
  }

  return potentialCelebrity;
}

// Method 3

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n,0);
        vector<int>outdegree(n,0);
        
        for(int i=0;i<trust.size();i++)
        {
            int x=trust[i][0]-1;
            int y=trust[i][1]-1;
            indegree[y]++;
            outdegree[x]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==n-1 and outdegree[i]==0)
                return i+1;
        }
        return -1;
    }
