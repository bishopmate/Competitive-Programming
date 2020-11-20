#include<bits/stdc++.h>
#define int long long
#define PI 3.14159265
int mod = 1000000009;
#define fi(i,start,end) for(int i=0; i<n; i++)
#define pb(x) push_back(x)
#define int long long
#define PI 3.14159265
#define all(v) v.begin(), v.end()
#define endl cout<<"\n" 
#define ll long long
#define dbg(x) cout<<#x<<" "<<x;endl;
#define bye endl;return
using namespace std;
template<typename T>



void debug(vector<T> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    cout<<"\n";
}
/*
1
8 6
1 2 4 1 2 4 1 2

*/


void solve(){

    string s;
    cin>>s;
    map<char, stack<int>> ma;
    int n = s.size();
    vector<bool> visited(n);
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++){
        ma[s[i]].push(i);
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x-1 >= 0 && !visited[x-1]){
            q.push(x-1);
            visited[x-1] = true;
            parent[x-1] = x;
        }
        if(x+1 < n && !visited[x+1]){
            q.push(x+1);
            visited[x+1] = true;
            parent[x+1] = x;
        }
        char c = s[x];
        while(!ma[c].empty()){
            int y = ma[c].top();
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
            ma[c].pop();
        }
    }
    int temp = n-1;
    int len = 0;
    while(temp != -1){
        if(parent[temp] != -1){
            len++;
        }
        temp = parent[temp];
    }
    cout<<len;endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
