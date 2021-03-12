long long int fastExpo(int a,int b)
{
    long long int ans=1;
    while(b>0)
    {
        if(b&1)
        ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    return ans;
}
