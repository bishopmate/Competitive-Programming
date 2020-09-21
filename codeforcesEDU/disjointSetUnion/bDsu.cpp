#include<bits/stdc++.h>
#define int long long
using namespace std;
// int rank[100006], parent[100006];  
int get(int a, int parent[]){
  return  (parent[a] == a ? a : get(parent[a], parent));
}

void unionDSU(int a, int b, int rank[], int parent[], int mnm[], int mxm[], int aukaat[]){
  a = get(a, parent);
  b = get(b, parent);
  if(a==b)
    return;
  if(rank[a] == rank[b])
    rank[a]++;
  if(rank[a] > rank[b]){
    int nMnm = min(mnm[a], mnm[b]);
    int nMxm = max(mxm[a], mxm[b]);
    mnm[a] = nMnm;
    mxm[a] = nMxm;
    aukaat[a] += aukaat[b]; 
    parent[b] = a;
  }else{

    int nMnm = min(mnm[a], mnm[b]);
    int nMxm = max(mxm[a], mxm[b]);
    mnm[b] = nMnm;
    mxm[b] = nMxm;
    aukaat[b] += aukaat[a];
    parent[a] = b;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin>>n>>m;
  int parent[n+1], rank[n+1], mnm[n+1], mxm[n+1], aukaat[n+1];
  for(int i=1; i<= n; i++){
    parent[i] = i;
    rank[i] = 0;
    mnm[i] = i;
    mxm[i] = i;
    aukaat[i] = 1;
  }
  while(m--){
    string s;
    cin>>s;
    if(s == "union"){
      int a,b;
      cin>>a>>b;
      unionDSU(a, b, rank, parent, mnm, mxm, aukaat);
    }else{
      int a; cin>>a;
      a = get(a, parent);
      cout<<mnm[a]<<" "<<mxm[a]<<" "<<aukaat[a]<<"\n";
    }
  }
  
  return 0;
}