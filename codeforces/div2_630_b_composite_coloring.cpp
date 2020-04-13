// Link - 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll smallest_divisor(ll n){
    
    while(n%2==0){
    
        n = n/2;
        return 2;
    }
    
    for(ll i = 3;i<= sqrt(n); i+=2){
        while(n%i==0){
            return i;
            n = n/i;
        }
    }
    
    if(n>2){
        return n;
    }
    
}

void test_case(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll,vector<ll>> m;
    for(ll i=0;i<n;++i){
        cin>>v[i];
        ll smallest_div = smallest_divisor(v[i]);
        m[smallest_div].push_back(i);
    }
    int i=1;
    for(auto x:m){
        for(auto ele:x.second){
            v[ele] = i; 
        }
        i++;
    }
    cout<<i-1<<"\n";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        test_case();
    }
}
