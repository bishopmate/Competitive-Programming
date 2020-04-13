// Link - https://codeforces.com/contest/1320/problem/A
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,x;
    cin>>n;
    vector<pair<ll,ll>> v;
    for(ll i=1;i<=n;++i){
        cin>>x;
        
        v.push_back(make_pair(x-i,x));

    }
    sort(v.begin(),v.end());

    ll max=v[0].second;
    ll current = v[0].first;
    ll current_sum = max;
    for(ll i=2;i<=n;++i){
        if(current==v[i-1].first){
            
            current_sum += v[i-1].second;
            
        }else{

            current_sum = v[i-1].second;
            current = v[i-1].first;
        }
        if(max<current_sum)
            max = current_sum;
    }
    cout<<max<<"\n";
    return 0;
}
