#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//template<typename T>
#define o_set(T) tree<T, null_type,greater<T>, rb_tree_tag,tree_order_statistics_node_update>



#define fast ios::sync_with_stdio(false);cin.tie(0);cout<<setprecision(25)
#define pb push_back
#define I insert
#define F first
#define S second
#define digit(x) floor(log10(x))+1
const long long M1=1000000007;
const long long  M2=998244353;
#define L_MAX 1e18
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;
using iii = tuple<ll,ll,ll>;
using matrix = vector<vector<ll>>;
using arr = vector<ll>;
using vs = vector<string>;
using pv = vector<ii>;
using umap = unordered_map<ll,ll>;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
template<typename T>
void showArr(T a){
    for(auto i : a) cout<<i<<" ";
    cout<<endl;
}
bool isValid(ll x,ll y,ll n,ll m,bool vis[][1005]){
    return (x>=0 and y>=0 and x<n and y<m and vis[x][y]==0);
}
ll power(ll a,ll n,ll m){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=(ans%m * a%m)%m;
        }
        n=n>>1;
        a=(a%m*a%m)%m;
    }
    return ans;
}

ll dx[]={-1,1,0,0},dy[]={0,0,-1,1};
//ll dx[]={-1,1,-1,1,0,0,-1,1} , dy[]={-1,1,0,0,-1,1,1,-1};
ll size=0;

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    matrix a(n,arr(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ll strength=-1,asize=0;
    bool vis[1005][1005]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                size=0;
                stack<pair<ll,ll>> st;
                st.push(make_pair(i,j));
                bool done = false;
                while(!st.empty()){
                    i = st.top().first, j = st.top().second;
                    st.pop();
                    if(!vis[i][j]){
                        vis[i][j] = 1;
                        size++;
                    }
                    done = true;
                    for(int k=0; k<4; k++){
                        ll x = i+dx[k];
                        ll y = j+dy[k];
                        if(x>=0 and y>=0 and x<n and y<m and vis[x][y]==0 and a[x][y] == a[i][j] ){
                            st.push(make_pair(x,y));
                        }
                    }
                    
                }

                if(size>asize){
                    asize=size;
                    strength=a[i][j];
                }
                if(size==asize){
                    strength=min(strength,a[i][j]);
                }
            }
        }
    }
    cout<<strength<<" "<<asize<<endl;
    return 0;
}
