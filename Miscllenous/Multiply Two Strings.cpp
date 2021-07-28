// leetcode : 43
// https://leetcode.com/problems/multiply-strings/
// for theory watch pep coding video
// Approcach:
// Our ans length will (length of num1 + length of num2).
// WE WILL START STORING ANS FROM ans[len1+len2] ..and decrement -1 for each iteration of j
// for outer loop , k will be reset to 1 less than previous k
// Watch video of pep coding
        

string multiply(string num1, string num2) {
        if(num1[0]=='0' or num2[0]=='0')
            return "0";
        
        int len1=num1.length();
        int len2=num2.length();
        
        int carry;
        vector<int>ans(len1+len2,0);
        int x=len1+len2;
        int p=0,k;
        
        for(int i=len2-1;i>=0;i--)
        {
            x--;
            k=x;
            carry=0;
            int y=num2[i]-'0';
            for(int j=len1-1;j>=0;j--)
            {
                int x=num1[j]-'0';
                int num=x*y+carry;
                if((ans[k]+num%10)>9)
                    ans[k-1]+=1;
                ans[k]=(ans[k]+num%10)%10;
                carry=num/10;
                k--;
            }
             if(carry)
                ans[k]+=carry;
        }
        string f_ans="";
        while(ans[0]==0)
            ans.erase(ans.begin());
        for(auto x:ans)
            f_ans+=(x+'0');
        return f_ans;
        
    }
