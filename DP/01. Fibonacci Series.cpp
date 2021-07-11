#include <iostream>
using namespace std;

int dp[1000]={0};

int  fibo(int n)
{
    if(n<=2)
        return dp[n]=n;

    if(dp[n])
        return dp[n];
    int sum=fibo(n-1)+fibo(n-2);        
    dp[n]=sum;
    return sum;
}


int main() {
    cout<<fibo(15); //987
    cout<<fibo(5); // 8
}
