/*
Link : https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
Input : "231*+9-"
output : -4
*/

int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        for(auto x:S)
        {
            if(x>='0' and x<='9')
                st.push(x-'0');
            else
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                switch(x) 
                {
                    case '+': st.push(a+b);
                    break;
                    case '-': st.push(a-b);
                    break;
                    case '*' : st.push(a*b);
                    break;
                    case '/' :st.push(a/b);
                    break;
                }
                
            }
        }
        return st.top();
    }
