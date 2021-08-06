 #include<bits/stdc++.h>
 using namespace std;

 float nthSqrt(int x,int n) 
 {
    int low=0;
    int high=x;
    float ans=0;

    while(low<=high)
    {
        long mid=low+(high-low)/2;
        long long num=pow(mid,n);

        if(num==x)
        {
            ans= mid;
            break;
        }    
        else if(num<x)  // chota hai too ans save krte jayega
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;

    }
    int p=2;
    float inc=0.1;

    for(int i=1;i<=p;i++)
    {
        while(pow(ans,n)<=x)
            ans+=inc;
        ans-=inc;
        inc/=10;    
    }
    
     return ans;
}

int main()
{
    cout<<mySqrt(64,3);
}
