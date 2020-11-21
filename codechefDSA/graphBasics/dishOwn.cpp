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
const int N = 100005;
int getParent(int parent[], int x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = getParent(parent, parent[x]);
    }
}

void unite(int a, int b, int parent[], int best[]){
    int x = getParent(parent, a);
    int y = getParent(parent, b);
    if(x == y){
        cout<<"Invalid query!\n";
        return;
    }
    if(best[x] == best[y]){
        return;
    }else if(best[x] > best[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
    }
}
void solve(){
    int n;
    cin>>n;
    int parent[n+1];
    int scores[n+1];
    int best[n+1];
    for(int i=1; i<=n; i++){
        cin>>scores[i];
        best[i] = scores[i];
        parent[i] = i;
    }
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 0){
            int a,b;
            cin>>a>>b;
            unite(a, b, parent, best);
        }else{
            int x; cin>>x;
            x = getParent(parent, x);
            cout<<x;endl;
        }
    }
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
