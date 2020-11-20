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
void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<int> v(n);
    vector<int> helper(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        helper[i] = v[i];
    }
    vector<pair<int, int>> queries(p);
    for(int i=0; i<p; i++){
        cin>>queries[i].first>>queries[i].second;
    }

    sort(all(v));
    map<int, int> ma;
    int cur = 1;
    ma[v[0]] = 1;
    for(int i=1; i<n; i++){
        if(v[i] - v[i-1] <= k){
            ma[v[i]] = cur;
        }else{
            cur++;
            ma[v[i]] = cur; 
        }
    }
    for(auto x:queries){
        if(ma[helper[x.first-1]] == ma[helper[x.second-1]]){
            cout<<"Yes";endl;
        }else{
            cout<<"No";endl;
        }
    }
    

}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
