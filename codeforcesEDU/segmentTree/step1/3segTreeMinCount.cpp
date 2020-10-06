#include<bits/stdc++.h>
using namespace std;
struct item{
  int m, c;
};

item calculateMinimum(item& a, item& b){
  item temp;
  if(a.m < b.m){
    temp.m = a.m;
    temp.c = a.c;
  }else if(a.m > b.m){
    temp.m = b.m;
    temp.c = b.c;
  }else{
    temp.m = a.m;
    temp.c = a.c+b.c;
  }
  return temp;
}

struct segTree{

  int size;
  vector<item> values;


  void init(int n){
    size = 1;
    while(size < n)  size *= 2;
    item temp = {INT32_MAX, 1};
    values.assign(2*size, temp);
  }

  void build(vector<int>& a, int x, int lx, int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        item temp = {a[lx], 1};
        values[x] = temp;
      }
      return;
    }

    int mx = (lx+rx)/2;
    build(a, 2*x+1, lx, mx);
    build(a, 2*x+2, mx, rx);
    values[x] = calculateMinimum(values[2*x+1], values[2*x+2]); 
  }

  void build(vector<int>& a){
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      item temp = {v, 1};
      values[x] = temp;
      return;
    }
    
    int m = (lx+rx)/2;
    if(i < m){
      set(i, v, 2*x+1, lx, m);
    }else{
      set(i, v, 2*x+2, m, rx);
    }
    values[x] = calculateMinimum(values[2*x+1], values[2*x+2]);

  }

  void set(int i, int v){
    set(i, v, 0, 0, size);
  }

  item calculate(int l, int r, int x, int lx, int rx){
    
    if(lx >= r || l >= rx){
      item temp = {INT32_MAX, 1};
      return temp;
    }
    if(lx >= l && rx <= r){
      return values[x];
    }

    int m = (lx + rx)/2;
    item left = calculate(l, r, 2*x+1, lx, m);
    item right = calculate(l, r, 2*x+2, m, rx);
    
    return  calculateMinimum(left, right);

  }

  item calculate(int l, int r){
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
      item ans = st.calculate(l,r);
      cout<<ans.m<<" "<<ans.c<<"\n";
    }

  }


  return 0;
}