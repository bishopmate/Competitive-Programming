#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
ll mod = 1000000007;
using namespace std;
struct classComp{
    bool operator()(const int& lhs, const int& rhs)const{
        return lhs > rhs;
    }
};
/*
1
17 3
10000000000010000
*/

void dpHelper(vector<ll>& a, vector<ll>& dp, ll n){

    for(ll i=0; i<n; i++){
        if(i==0){
            dp[i] = 1;
        }else if(a[i]>=a[i-1]){
            dp[i] = dp[i-1]+1;
        }else{
            dp[i] = 1;
        }
    }
    
}

void solve(){

    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<ll> dp(n,-1);
    dpHelper(arr, dp, n);
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += dp[i];
    } 
    cout<<ans<<"\n";
 
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}