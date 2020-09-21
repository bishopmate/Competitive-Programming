#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(vector<int> v, int n, int m, int k){
    int req = m*k;
    int have = 0;
    for(int i=0; i<n; i++){
        have += min(v[i],m);
    }
    // cout<<"req "<<req<<" have "<<have<<" ";
    return (have >= req);

}
signed main(){
    int k,n;
    cin>>k>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        sum += v[i];
    }
    int l = 0, r = (sum/k)+1;
    // cout<<l<<" "<<r<<endl;
    while(l+1 < r){
        int m = (l+r)/2;
        if(check(v,n,m,k)){
            // cout<<"success "<<m<<" "<<endl;
            l = m;
        }else{
            r = m;
            // cout<<"fail "<<m<<" "<<endl;
        }
    }
    cout<<l<<endl;
    return 0;
}