#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
ll mod = 1000000009;
using namespace std;
template<typename T>

void debug(vector<T> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    cout<<"\n";
}


ll dpHelper(vector<ll>& dp, ll n){
    
    if(dp[n]!=-1){
        return dp[n];
    }else{
        int x = dpHelper(dp,n-3);
        int y = dpHelper(dp, n-2);
        if(x==-1 && y== -1){
            dp[n] = -1;
        }else if(x == -1){
            dp[n] = y;
        }else if(y == -1){
            dp[n] = x;
        }else{
            dp[n] = ((x%mod +y%mod)%mod);
        }
        return dp[n];
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    vector<ll> dp(1e6+5, -1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    ll x,y;

    for(ll i=4; i<=1e6; i++){
        dp[i] = dpHelper(dp, i);
    }
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
