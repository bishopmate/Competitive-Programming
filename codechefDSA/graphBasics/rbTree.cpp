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

const int mod = 998244353;
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
    int q;
    cin>>q;
    int ctr = 0;
    while(q--){
        string query;
        cin>>query;
        int x,y;
        if(query == "Qi"){
            ctr++;
            continue;
        }
        cin>>x>>y;
        
        vector<int> xHelper, yHelper;
        while(x > 0){
            xHelper.push_back(x);
            x = x/2;
        }
        while(y > 0){
            yHelper.push_back(y);
            y = y/2;
        }
        int ans = 0;
        reverse(all(xHelper)); reverse(all(yHelper));
        int lca = 1;
        int counter = 0;
        int idx = 0;
        for(int i=0, j=0; i < xHelper.size() && j < yHelper.size(); i++, j++){
            if(xHelper[i] == yHelper[j]){
                lca = xHelper[i];    
                idx = i;
                counter++;
            }
        }

        int red = 0, black = 0, xCounter = 0, yCounter = 0;
        if(counter & 1){
            black++;
            xCounter = 1;   yCounter = 1;
        }else{
            red++;
        }
        for(int i = idx+1; i < xHelper.size(); i++){
            if(xCounter & 1){
                red++;
            }else{
                black++;
            }
            xCounter++;
        }
        for(int i = idx+1; i < yHelper.size(); i++){
            if(yCounter & 1){
                red++;
            }else{
                black++;
            }
            yCounter++;
        }
        if(ctr%2 == 0){
            if(query == "Qb"){
                cout<<black;endl;
            }else{
                cout<<red;endl;
            }
        }else{
            if(query == "Qb"){
                cout<<red;endl;
            }else{
                cout<<black;endl;
            }
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
