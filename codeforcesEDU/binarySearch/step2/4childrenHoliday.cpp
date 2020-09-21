#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(vector<tuple<int, int, int>>& v, int t, int m){
    int done = 0;
    for(auto x: v){
        int a,b,c;
        tie(a,b,c) = x;
        int total = a*b + c;
        int last = t%total;
        if(last > a*b){
            last = a*b;
        }
        done += ((t/total)*b + (last)/a);
    }
    return done >= m;
}
signed main(){
    int m,n;
    cin>>m>>n;
    vector<tuple<int, int, int>> v(n);
    int x,y,z;
    int mxm = 1e9;
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        tuple<int, int, int> tup = {x,y,z};
        v[i] = (tup);
        mxm = max(x,mxm);
    }
    int l = 0, r = mxm*m;
    while(l+1 < r){
        int mid = (l+r)/2;
        if(check(v, mid, m)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r<<"\n";
    int t = r;
    int remaining = m, done = 0;
    for(auto x: v){
        int a,b,c;
        tie(a,b,c) = x;
        int total = a*b + c;
        int last = t%total;
        if(last > a*b){
            last = a*b;
        }
        int cur = ((t/total)*b + (last)/a);
        done += cur;
        if(remaining > 0){
            if(done >= m){
                cout<<remaining<<" ";
                remaining = 0;
            }else{
                cout<<cur<<" ";
                remaining -= cur;
            }
        }else{
            cout<<0<<" ";
        }
    }

    return 0;
}