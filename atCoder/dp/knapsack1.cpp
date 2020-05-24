#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
void solve(){
	ll n,w;
	cin>>n>>w;
	ll a[n][2];
	for(ll i=0; i<n; ++i){
		cin>>a[i][0]>>a[i][1];
	}
	cout<<endl;
	ll dp[w+1][n+1];
	for(int i=0; i<=w; ++i){
		for(int j=0; j<=n; ++j){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}else if(a[j-1][0] <= i){
				dp[i][j] = max(dp[i - a[j-1][0]][j-1]+a[j-1][1], dp[i][j-1]);
			}else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	
	cout<<dp[w][n]<<"\n";
	
	
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}