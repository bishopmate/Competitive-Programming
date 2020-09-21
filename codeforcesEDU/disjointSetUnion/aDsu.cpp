#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int get(int a, int parent[]){
  return  (parent[a] == a ? a : get(parent[a], parent));
}

void unionDSU(int a, int b, int rank[], int parent[]){
  a = get(a, parent);
  b = get(b, parent);
  if(rank[a] == rank[b])
    rank[a]++;
  if(rank[a] > rank[b]){
    parent[b] = a;
  }else{
    parent[a] = b;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin>>n>>m;
  int parent[n+1], rank[n+1];
  for(int i=1; i<= n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
  while(m--){
    string s;
    cin>>s;
    int a,b;
    cin>>a>>b;
    if(s == "union"){
      unionDSU(a, b, rank, parent);
    }else{
      a = get(a, parent);
      b = get(b, parent);
      if(a == b){
        cout<<"YES\n";
      }else{
        cout<<"NO\n";
      }
    }
  }  
  
  return 0;
}
