#include<bits/stdc++.h>
using namespace std;
vector<int> gr[51];
int vis[51];
int gcdBinary(int a, int b, int res){
	if(a == b){
			return a * res;
	}
	if(a == 0){
			return b*res;
	}else if(b == 0){
			return a*res;
	}
	if(!(a&1) && !(b&1)){
			return gcdBinary((a >> 1), (b >> 1), res*2);
	}else if(!(a&1)){
			return gcdBinary((a >> 1), b, res);
	}else if(!(b&1)){
			return gcdBinary(a, (b >> 1), res);
	}else if(a > b){
			return gcdBinary(a-b, b, res);
	}else{
			return gcdBinary(a, b-a, res);
	}
}
void dfs(int u, int pr){
	for(auto v:gr[u]){
		if(!vis[v] && v != pr){
			vis[v] = true;
			dfs(v, u);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		int ma = 0;

		int hcf;
		int mxm = INT32_MIN;
		for(int i=0; i<n; i++){
			cin>>v[i];
			if(v[i] == 47)
				ma++;
		}
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(gcdBinary(v[i], v[j], 1) == 1){
					gr[i].push_back(j);
					gr[j].push_back(i);
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		int components = 0;
		for(int i=0; i<n; i++){
			if(!vis[i]){
				vis[i] = true;
				components++;
				if(components > 1)
					break;
				dfs(i, i);
			}
			if(components > 1)
				break;
		}
		if(components == 1){
			cout<<0<<endl;
			for(int i=0; i<n ;i++){
				cout<<v[i]<<" ";
			}cout<<endl;
		}else{
			if(ma == n){
				v[0] = 43;
			}else{
				v[0] = 47;
			}

			cout<<1<<endl;
			for(int i=0; i<n ;i++){
				cout<<v[i]<<" ";
			}cout<<endl;
		}
		for(int i=0; i<50; i++) gr[i].erase(gr[i].begin(), gr[i].end());
	}
	return 0;
}



