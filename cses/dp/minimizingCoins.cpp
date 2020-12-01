#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;
int inf = INT32_MAX;
const int N = 1e6+5;
int dp[N];
signed main(){
  int n,money;
  cin>>n>>money;
  int coins[n];
  for(int i=0; i<n; i++){
    cin>>coins[i];
  }
  dp[0] = 0;
  for(int i=1; i<=money; i++){
    dp[i] = inf;
    for(int j=0; j<n; j++){
      if(i-coins[j] >= 0 && dp[i-coins[j]] != inf){
        dp[i] = min(dp[i], dp[i-coins[j]]+1);
      }
    }
  }
  if(dp[money] != inf)
    cout<<dp[money]<<endl;
  else
    cout<<-1<<endl;
  return 0;
}