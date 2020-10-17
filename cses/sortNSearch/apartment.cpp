#include<bits/stdc++.h>
#define fi(i,n) for(int i=0;i<n;i++)
#define fj(j,m) for(int j=0;j<m;j++)
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    sort(a,a+n);
    sort(b,b+m);
    int count = 0;int j = 0;
    fi(i,n){
        if(j>=m)
            break;
        int nx = a[i]-k,px = a[i]+k;
        if(b[j]>=nx&&b[j]<=px){
            count++;
            j++;
        }else if(b[j]>=px){
            
        }else if(b[j]<=nx){
            i--;j++;
        }
        
    }  
    cout<<count<<endl; 
    

}
