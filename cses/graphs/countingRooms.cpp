#include<bits/stdc++.h>
using namespace std;
/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/

bool isValid(int i, int j, int n, int m){
    return (i>=0 && i<n && j>=0 && j<m);
}
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    return 0;
}