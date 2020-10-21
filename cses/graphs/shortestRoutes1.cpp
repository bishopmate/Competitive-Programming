#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
Sample Input
3 4
1 2 6
1 3 2
3 2 3
1 3 4
Sample Output
0 5 2
*/
 
void dijkstra(vector<vector<pair<int,int>>>& edge, vector<int>& D, vector<bool>& vis){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    D[1] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
          continue;
        vis[u] = true;
        for(auto x:edge[u]){
            int v = x.first, cost = x.second;
            if(D[v] > D[u]+cost){
                D[v] = D[u] + cost;
                pq.push({D[v], v});
            }            
        }
    }
}
 
signed main(){
    
    int v,e,a,b,w;
    cin>>v>>e;
    vector<vector<pair<int,int>>> edge(v+1);
    vector<int> D(v+1,INT64_MAX);
    vector<bool> vis(v+1, false);
    
    while(e--){
        cin>>a>>b>>w;
        edge[a].push_back({b,w});
    }
    dijkstra(edge, D, vis);  
    for(int i=1;i<=v;++i){
        cout<<D[i]<<" ";
    }
    return 0;
}
