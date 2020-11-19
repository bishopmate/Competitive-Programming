#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
ll mod = 1000000007;
using namespace std;
struct classComp{
    bool operator()(const int& lhs, const int& rhs)const{
        return lhs > rhs;
    }
};
/*
1
acbdbbd
zxywyye
5
a->z
c->x
b->y
d->w
w->e
1
d
e
2
d->w
w->e
*/
void dfs(vector<int> graph[],int target, int c, bool visited[], bool& possible){
    if(!visited[c]){
        visited[c] = true;
        if(c==target){
            possible = true;
            return;
        }
    }
    for(auto x: graph[c]){
        if(!visited[x])
            dfs(graph, target, x, visited, possible);
    }
}

void solve(){

    string s1, s2;
    cin>>s1>>s2;

    int m;
    cin>>m;
    vector<int> graph[26];  
    char c,d;
    string helper;
    for(int i=0; i<m; i++){
        cin>>helper;c = helper[0];d = helper[3];
        graph[c - 'a'].push_back(d - 'a');
    }
    bool possible = true;
    if(s1.length() != s2.length()){
        cout<<"NO\n";return;
    }
    for(int i=0; i< (int)s1.length(); i++){
        if(s1[i] != s2[i]){
            possible = false;
            bool visited[26] = {0};
            dfs(graph, s2[i] - 'a', s1[i] - 'a', visited, possible);
            
        }
        if(!possible)
            break;
    }
    if(possible)    cout<<"YES\n";
    else    cout<<"NO\n";

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
