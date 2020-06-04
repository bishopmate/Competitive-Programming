#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <climits>

#define fi(i,start,end) for(int i=0; i<n; i++)
#define pb push_back
#define int long long
#define PI 3.14159265
#define all(v) v.begin(), v.end()
#define endl cout<<"\n" 
#define ll long long

using namespace std;


void debug(vector<ll> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    endl;
}

bool cmp(int a, int b){ return a > b;}
ll dfsToCalculateSizes(vector<vector<ll>>& graph, ll u, ll v, vector<ll>& sizes){
    sizes[u] = 1;// counting itself
    for(auto x: graph[u]){
        if(x==v)    continue;
        sizes[u] += dfsToCalculateSizes(graph, x, u, sizes);    
    }
    return sizes[u];
}

void dfsToCalculateDepths(vector<vector<ll>>& graph, ll u, ll v, vector<ll>& depths){
    depths[u] = depths[v] + 1;
    for(auto x: graph[u]){
        if(x==v)    continue;
        dfsToCalculateDepths(graph, x, u, depths);
    }
    return ;    
}

void solve(){
    
    ll n,k,x,y;
    cin>>n>>k;
    vector<vector<ll>> graph(n+1);
    vector<ll> sizes(n+1, 0);
    vector<ll> depths(n+1, -1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x); // comment for directed graph case
    }
    x = dfsToCalculateSizes(graph, 1, 0, sizes);// This is a reverse dfs
    dfsToCalculateDepths(graph, 1, 0, depths);
    vector<ll> profit(n+1,0);
    for(int i =1; i<=n; i++){
        profit[i] = depths[i] - sizes[i] + 1;
    }
    
    sort(profit.begin()+1, profit.end(),greater<int>());
    ll ans = 0;
    // debug(sizes);debug(depths);debug(profit);
    // nth_element(profit.begin(), profit.end()+n-k, profit.end(), cmp);
    for(int i=1; i<=k; i++){
        ans += profit[i];
    }
    cout<<ans;endl;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
