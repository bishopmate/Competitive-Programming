#include<bits/stdc++.h>
using namespace std;

const int N = 100005, LOGN = 22;
/*
1
13 5
1 2 3 4 5 6 7 8 9 10 11 12 13
1 2
1 3
2 4
2 5
3 10
3 11
4 9
5 6
6 8
6 7
11 12
7 13
4 5
6 9
10 11
8 13
4 11
*/

// in normal graphs we need visited array for sure
// in trees we can do without it also
int lca(int u, int v, vector<int>& h, vector<vector<int>>& p, vector<vector<int>>& val){
  int ans = 0;
  if(h[u] < h[v]) swap(u,v);
  // to make sure h[u] >= h[v]
  int diff = h[u] - h[v];
  // Step 1 - Kill the diff

  for(int i=0; i < LOGN ; i++){
    if((diff & ( 1 << i)) != 0){ // If diff has i_th bit on then
    // diif AND 2^i != 0
      ans = ans ^ val[u][i]; 
      u = p[u][i];
    }
  }

  if( u == v) return (ans ^ val[u][0]);

  for(int i = LOGN -1; i >= 0; i--){
    if(p[u][i] != p[v][i]){
      ans = ans ^ val[u][i];
      ans = ans ^ val[v][i];
      u = p[u][i];  
      v = p[v][i];
    }
  }

  return (ans ^ val[u][0] ^ val[v][0] ^ val[p[u][0]][0]);

}

void dfs(int u, int prv, vector<vector<int>>& p,vector<vector<int>>& val, vector<int>& A, vector<int>& h, vector<vector<int>>& adj){
  h[u] = h[prv] + 1;
  
  p[u][0] = prv;
  val[u][0] = A[u];
  // for(int i = 1; i < LOGN; i++){ // calculating p[u][] array
  //   p[u][i] = p[p[u][i-1]][i-1];
  // }

  for(auto v:adj[u]){
    if(v == prv)  continue;
    dfs(v,u,p,val,A,h,adj);
  }
}

void solve(){
  int n,q,u,v;
  cin>>n>>q;

  vector<vector<int>> adj(n+1);
  vector<int> A(n+1), h(n+1);
  vector<vector<int>> p(n+1, vector<int>(LOGN));
  vector<vector<int>> val(n+1, vector<int>(LOGN));
  for(int i=1; i<=n; i++){
    cin>>A[i];
  }
  for(int i=1; i<n; i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  h[0] = 0;
  dfs(1, 0, p,val, A, h, adj);

  for(int i = 1; i < LOGN; i++){
    for(u=1; u <= n; u++){
      p[u][i] = p[p[u][i-1]][i-1];
      val[u][i] = val[p[u][i-1]][i-1] ^ val[u][i-1];
    }
  }

  while(q--){
    int u,v;
    cin>>u>>v;
    int x = lca(u, v, h, p, val);
    cout<<x<<endl;
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t = 1;
  cin>>t;
  while(t--)  solve();
  return 0;
}
