// Link to Problem - https://codeforces.com/contest/1330/problem/B

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n],maxi=0;
        for(ll i=0;i<n;++i){
            cin>>a[i];
            maxi = max(maxi,a[i]);
        }
        map<int,int> m;
        
        if(maxi<=n){
            ll count = 0,flag=1,x1=0,y1=0,x2=0,y2=0;
            for(int i=0;i<maxi;++i)m[a[i]]++;
          
            for(int i=1;i<=maxi;++i){
                if(m[i]!=1){
                    flag=0;break;
                }
            }
            m.clear();
            
                for(int i=maxi;i<n;++i)m[a[i]]++;
         
                for(int i=1;i<=(n-maxi);++i){
                    if(m[i]!=1){
                        flag=0;break;
                    }
                }
                
            
            if(flag==1){
                x1 = maxi; y1 = n-maxi;count++;
            }
            flag=1;
            m.clear();
        if(maxi*2!=n)
        {
            for(int i=0;i<(n-maxi);++i)m[a[i]]++;
            for(int i=1;i<=(n-maxi);++i){
                if(m[i]!=1){
                    flag = 0;break;
                }
            }
            m.clear();
            for(int i=(n-maxi);i<n;++i)m[a[i]]++;
            for(int i=1;i<=maxi;++i){
                if(m[i]!=1){
                    flag=0;break;
                }
            }
            if(flag==1){
                x2 = n-maxi; y2= maxi;count++;
            }
        }
            cout<<count<<"\n";
            if(x1!=0) cout<<x1<<" "<<y1<<"\n";
            if(x2!=0) cout<<x2<<" "<<y2<<"\n";
            
        }
        
    }

}
