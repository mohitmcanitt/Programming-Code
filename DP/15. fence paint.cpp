// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#

long long countWays(int n, int k){
        // code here
        if(n==1)
            return k;
        long long same=k;
        long long diff=k*(k-1);
        long long total=same+diff;
        long m=1000000007;
        for(int i=3;i<=n;i++)
        {
            same=diff;
            diff=(total*(k-1))%m;
            total=same+diff;
        }
        return total%m;
    }
