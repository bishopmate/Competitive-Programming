#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> queries(q);
    for(int i=0; i<n; i++){
        cin>>queries[i];
    }
    for(int i=0; i<q; i++){
        bool found = false;
        int l = 0, r = n-1, m;
        while(l<=r){
            m = (l + (r-l)/2);
            if(v[m]==queries[i]){
                found = true;
                break;
            }else if(queries[i] < v[m]){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        if(found){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}