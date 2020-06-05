// Link - https://codeforces.com/contest/1255/problem/B
#include <bits/stdc++.h>

#define int long long
#define endl cout<<"\n" 
#define ll long long

using namespace std;

void debug(vector<ll> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    endl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    int x,y;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(make_pair(x,i+1));
    }
    if(n==m){
        if(n==2){
            cout<<-1;endl;return;
        }
        sort(v.begin(),v.end());
        int sum = 0;
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            if(i==(n-1)){
                sum += v[n-1].first+v[0].first;
                ans.push_back(make_pair(v[n-1].second,v[0].second));
            }else{
                sum += v[i].first+v[i+1].first;
                ans.push_back(make_pair(v[i].second,v[i+1].second));
            }
        }
        cout<<sum;endl;
        for(auto x:ans){
            cout<<x.first<<" "<<x.second;endl;
        }

    }else{
        cout<<-1;endl;
    }
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
