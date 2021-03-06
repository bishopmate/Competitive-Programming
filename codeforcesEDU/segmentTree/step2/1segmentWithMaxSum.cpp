#include<bits/stdc++.h>
#define int long long
using namespace std;
struct item{
  int suf,pre,sum,seg;
};

item calculateMaximumSegSum(item& a, item& b){
  item temp;
  temp.sum = a.sum + b.sum;
  temp.pre = max(a.pre, a.sum+b.pre);
  temp.suf = max(b.suf, b.sum+a.suf);
  temp.seg = max({a.seg, b.seg, a.suf+b.pre});
  return temp;
}

struct segmentTree{
  int size;
  vector<item> values;

  void init(int n){
    size = 1;
    while(size < n)   size *= 2;
    item temp = {0,0,0,0};
    values.assign(2*size, temp);
  }



  void build(vector<int>& a, int x, int lx, int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        item temp = {a[lx], a[lx], a[lx], a[lx]};
        values[x] = temp;
      }
      return;
    }
    int mx = (lx+rx)/2;
    build(a, 2*x+1, lx, mx);
    build(a, 2*x+2, mx, rx);
    values[x] = calculateMaximumSegSum(values[2*x+1], values[2*x+2]);
  }

  void build(vector<int> a){
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx){
    if((rx - lx) == 1){
      item temp = {v, v, v, v};
      values[x] = temp;
      return;
    }
    int mx = (lx+rx)/2;
    if(i < mx){
      set(i, v, 2*x+1, lx, mx);
    }else{
      set(i, v, 2*x+2, mx, rx);
    }
    values[x] = calculateMaximumSegSum(values[2*x+1], values[2*x+2]);
  }

  void set(int i, int v){
    set(i, v, 0, 0, size);
  }

  item calculate(int l, int r, int x, int lx, int rx){
    if(lx >= r || l >= rx ){
      item temp = {0, 0, 0, 0};
      return temp;
    }
    if(lx >= l && rx <= r){
      return values[x];
    }

    int mx = (lx+rx)/2;
    item left = calculate(l, r, 2*x+1, lx, mx);
    item right = calculate(l, r, 2*x+2, mx, rx);

    return calculateMaximumSegSum(left, right);
  }

  item calculate(int l ,int r){
    return calculate(l, r, 0, 0, size);
  }

};
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, q;
  cin>>n>>q;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin>>v[i];
  }
  segmentTree st;
  st.init(n);
  st.build(v);
  item helper = st.calculate(0, n);
  cout<<max(helper.seg, 0LL)<<endl;
  while(q--){
    int i, v;
    cin>>i>>v;
    st.set(i, v);
    helper = st.calculate(0, n);
    cout<<max(helper.seg, 0LL)<<endl;
  }
  return 0;
}