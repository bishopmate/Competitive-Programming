#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;
const int N = 1e6+5;
int dp[N];
signed main(){
  int n,money;
  cin>>n>>money;
  int coins[n];
  for(int i=0; i<n; i++){
    cin>>coins[i];
  }
  dp[0] = 1;
  for(int i=1; i<=money; i++){
    dp[i] = 0;
    for(int j=0; j<n; j++){
      if(i-coins[j] >= 0){
        dp[i] = (dp[i] + dp[i-coins[j]])%mod;
      }
    }
  }
  cout<<dp[money]<<endl;
  return 0;
}
