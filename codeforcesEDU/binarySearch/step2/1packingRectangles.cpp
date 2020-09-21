#include<bits/stdc++.h>
#define int long long
using namespace std;
// @author : sam000013
bool good(int x, int n, int a, int b){
    return ((x/a) * (x/b)) >= n;
}
int chooseR(int n, int a, int b){
    int r = 1;
    while(!good(r, n, a, b)){
        r = r*2;
    }
    return r;
}
signed main(){
    int w,h,n;
    cin>>w>>h>>n;
    int l = 0; // l is bad
    int r = chooseR(n, w, h); // r is good
    while(l+1 < r){
        int m = (l + (r-l)/2);
        if(good(m, n, w, h)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r;
    return 0;
}