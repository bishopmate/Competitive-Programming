#include<bits/stdc++.h>
using namespace std;

struct segTree{

  int size;
  vector<int> values;


  void init(int n){
    size = 1;
    while(size < n)  size *= 2;
    values.assign(2*size, INT32_MAX);
  }

  void build(vector<int>& a, int x, int lx, int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        values[x] = a[lx];
      }
      return;
    }

    int mx = (lx+rx)/2;
    build(a, 2*x+1, lx, mx);
    build(a, 2*x+2, mx, rx);
    values[x] = min(values[2*x+1], values[2*x+2]); 
  }

  void build(vector<int>& a){
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      values[x] = v;
      return;
    }
    
    int m = (lx+rx)/2;
    if(i < m){
      set(i, v, 2*x+1, lx, m);
    }else{
      set(i, v, 2*x+2, m, rx);
    }
    values[x] = min(values[2*x+1], values[2*x+2]);

  }

  void set(int i, int v){
    set(i, v, 0, 0, size);
  }

  int calculate(int l, int r, int x, int lx, int rx){
    
    if(lx >= r || l >= rx)
      return INT32_MAX;

    if(lx >= l && rx <= r){
      return values[x];
    }

    int m = (lx + rx)/2;
    int left = calculate(l, r, 2*x+1, lx, m);
    int right = calculate(l, r, 2*x+2, m, rx);
    
    return  min(left, right);

  }

  int calculate(int l, int r){
    return calculate(l, r, 0, 0, size);
  }

};

signed main(){
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  segTree st;
  st.init(n);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  st.build(a);
  while(m--){
    int op;
    cin>>op;
    if(op == 1){
      int i,v;
      cin>>i>>v;
      st.set(i, v);
    }else{
      int l, r;
      cin>>l>>r;
      cout<<st.calculate(l, r)<<"\n";
    }

  }


  return 0;
}