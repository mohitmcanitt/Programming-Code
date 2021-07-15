
// Leetcode 5
// video link : https://www.youtube.com/watch?v=jCOJk4UyO8w
//https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes,
i.e. fix i (index) as center and two indices as i1 = i+1 and i2 = i-1
Compare i1 and i2 if equal then decrease i2 and increase i1 and find the maximum length. 
Use a similar technique to find the even length palindrome.
Take two indices i1 = i and i2 = i-1 and compare characters at i1 and i2 and 
find the maximum length till all pair of compared characters are equal and store the maximum length.
Print the maximum length.

string longestPalindrome(string s) {
        int start=0;
        int end=0;
        int low,high;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            // even length
            low=i;
            high=i+1;
            while(low>=0 and high<n and s[low]==s[high])
            {
                if((end-start) <(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
            // odd length
            low=i;
            high=i+2;
            while(low>=0 and high<n and s[low]==s[high])
            {
                if((end-start)<(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
            
        }
        return s.substr(start,end-start+1);
    }
