// Problem Link - https://codeforces.com/problemset/problem/1277/B

#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
struct classComp{
    bool operator()(const int& lhs, const int& rhs)const{
        return lhs > rhs;
    }
};
void solve(){

    int n;
    cin>>n;
    set<int, classComp> s;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x%2==0){
            s.insert(x);
        }
    }
    int moves = 0;
    while(!s.empty()){
        int x = *(s.begin());
        x = x/2;
        if(x%2==0){
            s.insert(x);
        }
        s.erase(s.begin());
        moves++;
    }
    cout<<moves<<endl;


}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
