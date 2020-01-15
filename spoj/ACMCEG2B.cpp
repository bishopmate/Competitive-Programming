#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    cin>>n;
    map<ii, string> table;
    for(int i=0; i<n;i++)
    {
        ii code;
        string name;
        cin>>code.first>>code.second;
        cin>>name;
        table[code] = name;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ii code;
        cin>>code.first>>code.second;
        cout<<table[code]<<endl;
    }


    
}