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
 
const int mod = 1000000007;
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
struct number{
    int val;
    int k = 0;
    vector<int> kPrimes;
};
const int N = 100005;

 
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<bool> marker(N);
    vector<int> primes;
    for(int i=2; i<= N; i++){
        if(!marker[i]){
            primes.push_back(i);
            for(int j=i*i; j<=N; j+=i){
                marker[j] = true;
            }
        }
    }

    vector<number> dp(N);
    int countPrimes = primes.size();
    vector<vector<int>> helper(6, vector<int>(N));
    for(int i=2; i<=N; i++){
        for(int j=0; j<countPrimes && primes[j] <= i; j++){
            
            if(i%primes[j] == 0){
                dp[i].k = 1;
                dp[i].kPrimes.push_back(primes[j]);
                for(int k=0; k < dp[i/primes[j]].kPrimes.size(); k++){
                    if(dp[i/primes[j]].kPrimes[k] != primes[j]){
                        dp[i].kPrimes.push_back(dp[i/primes[j]].kPrimes[k]);
                        dp[i].k += 1;
                    }
                }
                break;
            }

        }
        for(int j = 1; j <= 5; j++){
            if(dp[i].k == j){
                helper[j][i] = helper[j][i-1] + 1;
            }else{
                helper[j][i] = helper[j][i-1];
            }
        }
            
    }

    
     

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int a,b,k;
        cin>>a>>b>>k;
        int ans;
        ans = helper[k][b] - helper[k][a-1];
        
        cout<<ans;endl;
    }
    return 0;
}
