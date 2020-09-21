#include<bits/stdc++.h>
#define int long long
using namespace std;

int getRepresentative(int a, int papa[]){
  return (papa[a] == a ? a : getRepresentative(papa[a], papa));
}

void unitePlayers(int a, int b, int papa[], int rank[], int exp[]){
  a = getRepresentative(a, papa);
  b = getRepresentative(b, papa);
  if(a == b)
    return;
  if(rank[a] == rank[b])
    rank[a]++;
  if(rank[a] > rank[b]){
    papa[b] = a;
    exp[b] += (exp[a]*(-1)); 
  }else{
    papa[a] = b;
    exp[a] += (exp[b]*(-1));
  }
}

void addExp(int a, int v, int papa[], int exp[]){
  a = getRepresentative(a, papa);
  exp[a] = exp[a] + v;
}

int getExp(int a, int papa[], int exp[]){
  return (papa[a] == a ? exp[a] : exp[a] + getExp(papa[a], papa, exp));
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,queries;
  cin>>n>>queries;
  int exp[n+1] = {0}, rank[n+1] = {0}, papa[n+1] = {0};
  for(int i=1; i<=n; i++){
    papa[i] = i;
  }
  vector<int> ans;
  while(queries--){
    string query;
    cin>>query;
    if(query == "join"){
      int x,y;
      cin>>x>>y;
      unitePlayers(x, y, papa, rank, exp);

    }else if(query == "add"){
      int x,v;
      cin>>x>>v;
      addExp(x, v, papa, exp);
    }else{
      int player;
      cin>>player;
      ans.push_back(getExp(player, papa, exp));
    }
  }
  for(auto x:ans){
    cout<<x<<endl;
  }

  return 0;
}