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


void solve(){

    

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;;
    cin>>t;
    while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<int> graph[n+1];
	    int x,y;
	    for(int i=0; i<m; i++){
	        cin>>x>>y;
	        graph[x].push_back(y);
	        graph[y].push_back(x);
	    }
	
	
	    vector<bool> visited(n+1, false);
	    visited[0] = true;
	    vector<int> helper;
	    int connectedComponents = 0;
	    int ans = 1;
	    for(int i=1; i<=n; i++){
	        stack<int> st;
	        if(!visited[i]){
	            int size = 0;
	            st.push(i);
	            while(!st.empty()){
	                int s = st.top();
	                if(!visited[s]){
	                    visited[s] = true;
	                    size++;
	                }
	                st.pop();
	                for(auto x:graph[s]){
	                    if(!visited[x])
	                        st.push(x);
	                }
	            }
	            helper.push_back(size);
	            connectedComponents++;
	        }
	        
	    }
	    for(auto x:helper){
	        ans = ((ans%mod) * (x%mod))%mod;
	    }
	    cout<<connectedComponents<<" "<<ans<<"\n";
	    
	


    }
    return 0;
}