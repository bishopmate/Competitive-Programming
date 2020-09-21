#include<bits/stdc++.h>
using namespace std;
bool check(int t, int x, int y, int n){
    return ((t/x) + (t/y) >= n);
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    if(x > y)   swap(x,y);
    n = n-1;
    int l = 0;
    int r = y*n;
    while(l + 1 < r){
        int m = (l + (r-l)/2);
        if(check(m, x, y, n)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r+x<<endl;


    return 0;
}