#include<bits/stdc++.h>
using namespace std;
/*
5 8
########
#.A#...#
#.##.#B#
#......#
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
    char v[1005][1005];
    bool vis[1005][1005];
    pair<int, int> start;
    pair<int, int> finish;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j] == 'A')
                start = make_pair(i,j);
            else if(v[i][j] == 'B')
                finish = make_pair(i,j);
 
        }
    }
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    parent[start.first][start.second] = make_pair(start.first, start.second);
    queue<pair<int, int>> q;
    q.push(make_pair(start.first, start.second));
    vis[start.first][start.second] = true;
    while(!q.empty() && !vis[finish.first][finish.second]){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int, int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if(next.first >= 0 && next.first < n && next.second >= 0 && next.second <m && (v[next.first][next.second] == '.' || v[next.first][next.second] == 'B') && !vis[next.first][next.second] ){
                parent[next.first][next.second] = make_pair(cur.first, cur.second);
                q.push(make_pair(next.first, next.second));
                vis[next.first][next.second] = true;    
            }
        }
    }
    vector<char> path;
    if(vis[finish.first][finish.second] == true){
        cout<<"YES\n";
        int dis = 0;
        pair<int, int> cur = make_pair(finish.first, finish.second);
        while(1){
            if(cur.first == start.first && cur.second == start.second)
                break;
            dis++;
            if(parent[cur.first][cur.second].first + dx[0] == cur.first && parent[cur.first][cur.second].second + dy[0] == cur.second){
                path.push_back('R'); 
            }else if(parent[cur.first][cur.second].first + dx[1] == cur.first && parent[cur.first][cur.second].second + dy[1] == cur.second){
                path.push_back('L');
            }else if(parent[cur.first][cur.second].first + dx[2] == cur.first && parent[cur.first][cur.second].second + dy[2] == cur.second){
                path.push_back('D');
            }else{
                path.push_back('U');
            }
            cur = parent[cur.first][cur.second];
        }
        cout<<dis<<endl;
        n = path.size();
        for(int i=n-1; i>=0; i--)
            cout<<path[i];
    }else{
        cout<<"NO"<<endl;
    }
 
    return 0;
}