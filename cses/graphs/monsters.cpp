#include<bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, int n, int m){
    return (i>=1 && i<=n && j>=1 && j<=m);
}
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
signed main(){
  int n,m;
  cin>>n>>m;
  char graph[n+1][m+1];
  bool visited[n+1][m+1];
  char firstArrived[n+1][m+1];
  queue<pair<int, int>> q;
  pair<int, int> myLocation;
  vector<vector<pair<int, int>>> parent(n+1, vector<pair<int, int>>(m+1));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>graph[i][j];
      visited[i][j] = false;

      if(graph[i][j] == 'M' || graph[i][j] == 'A'){
        parent[i][j] = make_pair(i,j);
        visited[i][j] = true;
      }

      if(graph[i][j] == 'M'){
        q.push(make_pair(i,j));
        firstArrived[i][j] = 'M';
      }else if(graph[i][j] == 'A'){
        myLocation.first = i; myLocation.second = j;
        firstArrived[i][j] = 'A';
      }else{
        firstArrived[i][j] = '-';
      }

    }
  }
  q.push(myLocation);

  while(!q.empty()){
    pair<int, int> u = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int newX = u.first+dx[i];
      int newY = u.second+dy[i];
      
      if(isValid(newX, newY, n, m) && !visited[newX][newY] && graph[newX][newY] != '#'){
        visited[newX][newY] = true;
        firstArrived[newX][newY] = firstArrived[u.first][u.second];
        parent[newX][newY] = u;
        q.push(make_pair(newX, newY));
      }

    }
  }


  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(firstArrived[i][j] == 'A'){
          if(i == 1 || i==n || j==1 || j==m){
            cout<<"YES\n";
              pair<int, int> cur = make_pair(i, j);
              vector<char> ans;

              while(parent[cur.first][cur.second] != cur){
                int diffX = cur.first - parent[cur.first][cur.second].first;
                int diffY = cur.second - parent[cur.first][cur.second].second;
                if(diffX == -1){
                  ans.push_back('U');
                }else if(diffX == 1){
                  ans.push_back('D');
                }else if(diffY == -1){
                  ans.push_back('L');
                }else{
                  ans.push_back('R');
                }
                cur = parent[cur.first][cur.second];
              }
              reverse(ans.begin(), ans.end());
              cout<<ans.size()<<endl;
              for(auto x:ans){
                cout<<x;
              }cout<<endl;
              return 0;
          }
      }
    }
  }
  cout<<"NO\n";
  return 0;
}
