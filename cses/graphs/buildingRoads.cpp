#include<bits/stdc++.h>
using namespace std;
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> clusters(n+1);
    vector<bool> vis(n+1);
    int k = 0;
    vector<int> helper;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            k++;
            stack<int> s;
            s.push(i);
            vis[i] = true;
            clusters[i] = k;
            helper.push_back(i);
            while(!s.empty()){
                int cur = s.top();
                s.pop();
                for(auto neighbor : adj[cur]){
                    if(!vis[neighbor]){
                        clusters[neighbor] = k;
                        s.push(neighbor);
                        vis[neighbor] = true;
                    }   
                }
            }
        }
    }
    if(k > 1){
        cout<<k-1<<endl;
        for(int i=0; i < (int)helper.size() - 1; i++)
            cout<<helper[i]<<" "<<helper[i+1]<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}