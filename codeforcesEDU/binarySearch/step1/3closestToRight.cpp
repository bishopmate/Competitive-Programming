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
    for(int i=0; i<q; i++){
        cin>>queries[i];
    }
    for(int i=0; i<q; i++){
        bool found = false;
        int l = -1; // a[l] < x
        int r = n; // a[r] >= x
        int m;
        while(r > l+1){
            m = (l + (r-l)/2);
            if(v[m] < queries[i])
                l = m;
            else
                r = m;
            
        }
        cout<<r+1<<"\n";
    }
    return 0;
}
