#include<bits/stdc++.h>
#define fi(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    set <int, greater<int>> a;
    int x;
    fi(i,n){
        cin>>x;
        a.insert(x);
    }
    cout<<a.size();
    
}