#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int h[n];
	for(int i=0; i<n; ++i){
		cin>>h[i];
	}
	
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(h[0]-h[1]);
	for(int i=2; i<n; ++i){
		int mnm = INT_MAX;
		for(int j = max(0,i-k); j<i; ++j){
			mnm = min(dp[j] + abs(h[j] - h[i]), mnm);
		}
		dp[i] = mnm;
		
	}
	cout<<dp[n-1]<<"\n";
}