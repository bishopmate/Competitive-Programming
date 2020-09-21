#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(double m, double c){
    return (m*m + sqrt(m) >= c);
}
signed main(){
    cout<<fixed<<setprecision(16);
    double c;
    cin>>c;
    double l = 0, r = c;
    while(l+0.000001 < r){
        double m = (l+r)/2;
        if(check(m, c)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r<<endl;
    return 0;
}