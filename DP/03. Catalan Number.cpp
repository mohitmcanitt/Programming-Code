/*

C0=1
C1=1
C2=C0C1+C1C0 ------> 1*1+1*1=2
C3=C0C2+C1C1+C2C0  ------> 1*2+1*1+2*1=5
C4=C0C3+C1C2+C2C1+C3C0  ------> 1*5+1*2+2*1+5*1=14

CN=C0CN-1+C1CN-2+C2CN-3+ ..... CN-1C0

*/
long long int nthCatlan(int n)
{
  
  int dp[n+1]={0};
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<=n;i++)
    for(int j=0;j<i;j++)
      dp[i]+=dp[j]*dp[i-j-1];
  return dp[n];
  
}
