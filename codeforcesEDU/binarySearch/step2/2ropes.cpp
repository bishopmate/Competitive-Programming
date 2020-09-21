#include<bits/stdc++.h>
using namespace std;
bool check(vector<double>& v, double len, int k, int n){
    int possible = 0;
    for(int i=0; i<n; i++){
        possible += (v[i]/len);
    }
    return (possible >= k);
}
int main(){
    double uni = 1.000000;
    double n,k;
    cin>>n>>k;
    vector<double> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    
    double l = 0, r = *max_element(v.begin(), v.end());
    while((l+0.000001) < (r)){
        double m = ((l+r)/2);
        if(check(v, m, k, n)){
            l = m;
        }else{
            r = m;
        }
    }
    printf("%.6f", l);
    return 0;
}