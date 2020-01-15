#include<bits/stdc++.h>
using namespace std;
// creating a pair which will contain the codeword for a person
typedef pair<int,int> ii;
int main(){
    int n;
    cin>>n;
    // creating a map which will contain codewords as keys and names as the corresponding values 
    map<ii, string> table;
    for(int i=0; i<n;i++)
    {
        ii code;
        string name;
        // fetching code word in two parts
        cin>>code.first>>code.second;
        // fetching the name corresponding to the codeword
        cin>>name;
        // storing them in a map
        table[code] = name;
    }
    // processing queries
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ii code;
        // fetching the queried codeword
        cin>>code.first>>code.second;
        // Outputting the corresponding string
        cout<<table[code]<<endl;
    }


    
}
