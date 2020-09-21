#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(string& t, string& c, int n, int m, int mid, vector<int>& v){
    string temp = "";
    vector<bool> helper(n);
    for(int i=0; i<mid; i++)
        helper[v[i]] = true;
    for(int i=0; i<n; i++){
        if(!helper[i]){
            temp += t[i];
        }
    }
    bool done = false;
    int i = 0, j=0;
    n = temp.size();
    // cout<<mid<<" "<<temp<<endl;
    while(i < n && j < m){
        if(temp[i]==c[j])
            j++;
        i++;
    }
    return j>=m;
}
signed main(){
    string t,c;
    cin>>t>>c;
    int n = t.size(), m = c.size();
    vector<int> v(n);
    int x;
    for(int i=0; i<n; i++){        
        cin>>x;
        v[i] = x-1;
    }
    int l = 0, r = n+1;
    while(l+1 < r){
        int mid = (l+r)/2;
        if(check(t,c,n,m, mid, v)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l<<"\n";
    
    return 0;
}