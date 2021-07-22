// GFG : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

/*
  Input :  a a b c c b c d
  Output : a # b b b # # d
  
  Time : o(n^2)
  Space : o(n)
  We will create a array of size 26 to store the frequency of each character.
  For particular index i,
    i.) We first increment frequency of ith index
    ii.) Run a loop from j->(0 to i)
    iii.) the moment we find freq[j] is 1. append freq character in our answer
    iv.) if there is no character , then append '#' in answer
    
  
*/

string FirstNonRepeating(string A){
		    // Code here
		    int freq[26]={0};
		    string ans="";
		   for(int i=0;i<A.length();i++)
		   {
		       freq[A[i]-'a']++;
		       int flag=0;
		       for(int j=0;j<=i;j++)
		       {
		           if(freq[A[j]-'a']==1)
		           {
		               ans+=A[j];
		               flag=1;
		               break;
		           }
		       }
		       if(flag==0)
		        ans+='#';
		   }
		   return ans;
		}

/*
Approach 2: Using Queue time 0(n) and space 0(n)
  create a queue.
  create a frequency array to store frequency of each element of string
  Run a loop from i->(o,n-1)
  
  for each i do following
  i) push into queue
  ii) Update frequecy of A[i]
  iii) pop element from queue if frequency of front element is greater than 1 . Do this 
  iv). If stack is not empty. append q.front() into ans
  v). If stack is empty append '#'
  
 */
string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    int freq[26]={0};
		    string ans="";
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        freq[A[i]-'a']++;
		        while(!q.empty())
		        {
		            if(freq[q.front()-'a']>1)
		                    q.pop();
		            else
		                {
		                    ans+=q.front();
		                    break;
		                }
		        }
		        if(q.empty())
		            ans+='#';
		    }
		    return ans;
		}
  
  
  




