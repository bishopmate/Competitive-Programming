#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    char mat[55][55];
    while(t--){
        int m,n,k;
        cin>>m>>n>>k;
        // initialising a vector whose elements denote the no of bulbs lit in the row, intially set to zero
        vector<int> bulbs_lit(m,0);
        // reading the cave details
        for(int r = 0; r<m; ++r){
            for(int c = 0; c<n; ++c){
                cin>>mat[r][c];
                // increasing by 1 the bulb lit for the particular row if char is '*'
                if(mat[r][c]=='*')
                    ++bulbs_lit[r];
            }
        }
        // sorting the bulbs in ascending order to toggle the row with the least lit 
        // bulbs so that when toggled it will maximize the bulbs lit
        sort(bulbs_lit.begin(), bulbs_lit.end(), less<int>());
        int i = 0;
        // litting the bulb only till the point it profits us
        while(k>0 && i<m && n - bulbs_lit[i] > bulbs_lit[i]){
            bulbs_lit[i] = n - bulbs_lit[i];
            k--;
            i++;
        }
        // if still we have remaining toggle chances then if the number of chances 
        // are even then we leave it as it is or else we toggle the row which has 
        // the least number of bulbs lit amongst all
        if(k>0 && k%2==1){
            vector<int>::iterator it = min_element(bulbs_lit.begin(),bulbs_lit.end());
            *it = n - *it;
        }
        // adding all the numbers of bulb lit which is our final answer
        cout<<accumulate(bulbs_lit.begin(),bulbs_lit.end(),0)<<"\n";


    }
}