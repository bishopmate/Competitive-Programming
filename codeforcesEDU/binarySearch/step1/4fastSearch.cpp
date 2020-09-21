#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cin>>q;
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i=0; i<q; i++){
        cin>>queries[i][0]>>queries[i][1];
    }

    for(int i=0; i<q; i++){
        int ans = 0;
        bool found = false;
        int l = -1; // a[l] < x
        int r = n; // a[r] >= x
        int m;
        while(r > l+1){
            m = (l + (r-l)/2);
            if(v[m] < queries[i][0])
                l = m;
            else
                r = m;
            
        }
        int left = r;
        l = -1, r = n;
        while(r > l+1){
            m = (l + (r-l)/2);
            if(v[m] <= queries[i][1])
                l = m;
            else
                r = m;
            
        }
        int right = l;
        cout<<(right-left+1)<<" ";
    }
    return 0;
}