bool solve(stack<char>st,char ch)
    {
        
        if(st.empty())
            return false;
        if(st.top()=='(' and ch==')')
            return true;
        if(st.top()=='{' and ch=='}')
            return true;
        if(st.top()=='[' and ch==']')
            return true;            
        return false;            
    }
    
    bool ispar(string S)
    {
        // Your code here
        stack<char>s;
        for(auto x:S)
        {
            if(x=='(' or x=='{' or x=='[')
                s.push(x);
            else
            {
                bool y=solve(s,x);
                if(!y)
                    return false;
                else 
                    s.pop();
            }
                
        }
        return s.empty()?true:false;
    }
