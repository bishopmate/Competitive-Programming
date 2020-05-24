#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a[n][3];
	for(int i=0; i<n; ++i){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	int dp[n][3] = {0};
	dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];
	for(int i=1; i<n; ++i){
		for(int j=0; j<3; ++j){
			
			if(j==0){
				dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
			}else if(j==1){
				dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i][1];
			}else{
				dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i][2];
			}
			
		}
	}
	int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	cout<<ans<<"\n";
	
	
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