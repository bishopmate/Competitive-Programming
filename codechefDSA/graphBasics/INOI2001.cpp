#include<bits/stdc++.h>
 
// @author : sam000013
 
#define int long long
#define PI 3.14159265
#define pb(x) push_back(x)
#define all(v) v.begin(), v.end()
#define endl cout<<"\n"     
#define dbg(x) cout<<#x<<" "<<x;endl;
#define bye endl;return
#define uni 1.000000
using namespace std;
 
const int mod = 1000000007;
template <typename T>
 
void debug(vector<T> x)
{
    for (auto e : x)
    {
        cout << e << " ";
    }
    cout << "\n";
}
 
/*
 
*/
void dfs(int u, vector<vector<int>>& gr, vector<bool>& vis, set<int>& employees){
    for(auto v: gr[u]){
        if(!vis[v]){
            vis[v] = true;
            employees.insert(v);
            dfs(v, gr, vis, employees);
        }
    }
}

void dfs(int u, vector<vector<int>>& gr, vector<bool>& vis, int level, int& strength){
    for(auto v:gr[u]){
        if(!vis[v]){
            strength += level;
            vis[v] = true;
            dfs(v, gr, vis, level+1, strength);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<bool> vis(n+1);
    int even = 0, odd = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            set<int> employees;
            employees.insert(i);
            vis[i] = true;        
            dfs(i, gr, vis, employees);
            int departmentSize = employees.size();
            for(auto x:employees)
                vis[x] = false;
            int head;
            if(departmentSize%2 == 0){
                head = *(employees.begin());
            }else{
                head = *(prev(employees.end()));
            }
            vis[head] = true;
            int strength = 1;
            dfs(head, gr, vis, 2, strength);

            if(departmentSize%2 == 0){
                even += strength;
            }else{
                odd += strength;
            }
        }
    }
    cout<<even<<" "<<odd;bye;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
