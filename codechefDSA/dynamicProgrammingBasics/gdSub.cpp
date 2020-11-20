#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;


signed main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  map<int, int> ma;
  vector<int> d;
  for(int i=0; i<n; i++){
    cin>>a[i];
    ma[a[i]]++;
    if(ma[a[i]] == 1)
      d.push_back(a[i]);
  }
  n = d.size();
  k = min(k, n);
  int dp[n][k+1];
  
  dp[0][0] = 1;
  dp[0][1] = ma[d[0]]+1;
  
  for(int i=2; i<=k; i++)
    dp[0][i] = dp[0][i-1];
  
  for(int i=1; i<n; i++){
    dp[i][0] = 1;
    for(int j=1; j<= k; j++){
      dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*ma[d[i]])%mod;
    }
  }
  cout<<dp[n-1][k]<<endl;

  return 0;
}
