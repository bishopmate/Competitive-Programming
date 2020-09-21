#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    string s;
    cin>>s;
    map<char, int> ma;
    int n = s.size();
    
    int nb, ns, nc;
    cin>>nb>>ns>>nc;
    int pb, ps, pc;
    cin>>pb>>ps>>pc;
    int rubles;
    cin>>rubles;
    for(int i=0; i<n; i++){
        ma[s[i]]++;
    }
    int l = 0, r = 1e14;
    // for(auto x:ma)
    //     cout<<x.first<<" "<<x.second<<endl;
    while(l+1 < r){
        int m = (l + ((r-l)/2));
        bool ok = true;
        int rnb = max((ma['B']*m - nb), (int)0), rns = max((ma['S']*m - ns), (int)0), rnc = max((ma['C']*m - nc), (int)0);
        
        int rubReq = (rnb*pb)+(rns*ps)+(rnc*pc);
        //cout<<"m "<<m<<" "<<rubReq<<endl;
        if(rubReq > rubles)
            ok = false;
        if(ok){
            l = m;
        }else{
            r = m;
        }
    }
    cout<<l<<endl;
    return 0;
}