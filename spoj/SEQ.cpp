#include<iostream>
#include<vector>
#define ll long long
#define pb push_back
#define MOD 1000000000
using namespace std;

ll k;
vector<ll> a,b,c;


vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){

    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    
    for(int i = 1; i <= k ;i++){
        for(int j = 1; j<=k;j++){
        
            for(int x = 1;x<=k;x++){
            
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            
            }
        
        }
    }

    return C;

}



vector<vector<ll>> pow(vector<vector<ll>> A, ll p){
    
    if(p==1)
        return A;
    if(p&1){
        return multiply(A,pow(A,p-1));
    }else{
        vector<vector<ll>> X = pow(A,p/2);
        return multiply(X,X);
    }

}



ll compute(ll n){
    // Base Case
    if(n==0)
        return 0;
    
    // When n<=k
    if(n<=k)
     return b[n-1];
    
    // Otherwise we have to use Matrix Exponentiation, indexing is from 1 over her
    vector<ll> F1(k+1);
    
    for(int i=1;i<=k;++i){
        F1[i] = b[i-1];
    }
    
    // Transformation Matrix
    vector<vector<ll>> T(k+1,vector<ll>(k+1));
    
    for(int i = 1;i<=k;i++){
        for(int j=1;j<=k;j++){
        
            if(i<k){
                if(j==i+1){
                    T[i][j] = 1;
                }else{
                    T[i][j] = 0;
                }
                continue;    
            }else{ // Last Row - store the coefficients in reverse order
            
                T[i][j] = c[k-j];
            
            }
            
            
        
        }
    } 
    //  T^n-1
    T = pow(T,n-1);
    
    // multiply by F1;
    ll res = 0;
    for(int i = 1; i <=k ;i++){
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    
    return res;
    
     
}


int main(){
    ll t, n, num;
    cin>>t;
    while(t--){
    
        cin>>k;
        
        
        // Init vector f1
        for(int i = 0 ; i < k ; i++){
            cin>>num;
            b.pb(num);
        }
        
        // Coefficients
        for(int i = 0 ; i < k ; i++){
            cin>>num;
            c.pb(num);
        }
        
        // value of n 
        cin>>n;
        cout<<compute(n)<<"\n";
        
        // Erasing all the values for next test case
        b.clear();
        c.clear();
    
    }

}

