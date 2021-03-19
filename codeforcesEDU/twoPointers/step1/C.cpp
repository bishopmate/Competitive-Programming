#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  ios::sync_with_stdio(false);cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  int a[n], b[m];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=0; i<m; i++){
    cin>>b[i];
  }
  int l=0,r=0;
  int ans = 0;
  int prev = INT64_MIN, count = 0;
  while(r < m){
    if(b[r] == prev){
      ans += count;
    }else{
      count = 0;
      while(l < n && a[l] <= b[r]){
        if(a[l] == b[r]){
          prev = a[l];
          count++;
        }
        l++;
      }
      if(count > 0){
        // cout<<prev<<" "<<count<<endl;
        ans += count;
      }
    }
    r++;
  }
  cout<<ans<<endl;
  return 0;
}