#include<bits/stdc++.h>
using namespace std;
/*
Sample Input
5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output
3
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
    int rooms = 0;
    int l = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && v[i][j] == '.'){
                rooms++;
                stack<pair<int, int>> s;
                s.push(make_pair(i,j));
                while(!s.empty()){
                    pair<int, int> cur = s.top();
                    // cout<<cur.first<<" "<<cur.second<<endl;
                    s.pop();
                    if(!vis[cur.first][cur.second]){
                        vis[cur.first][cur.second] = true;
                    }
                    for(int k=0; k<4; k++){
                        pair<int, int> next = make_pair(cur.first + dx[k], cur.second + dy[k]);
                        if(isValid(next.first, next.second, n, m) && !vis[next.first][next.second] && v[next.first][next.second] == '.'){
                            s.push(make_pair(next.first, next.second));
                        }
                    }
                }
            }
            
        }
    }
    cout<<rooms<<endl;
    return 0;
}
