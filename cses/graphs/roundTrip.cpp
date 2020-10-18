#include<bits/stdc++.h>
using namespace std;
bool cycleFound = false;
vector<int> cycle;
void dfs(int u, int p, vector<int>& parent, vector<char>& visited, vector<vector<int>>& graph){
  if(cycleFound)
    return;
  if(visited[u] == '2')
    return;
  

  
  if(visited[u] == '1'){
    cycleFound = true;
    int cur = p;
    cycle.push_back(cur);
    while(cur != u){
      cur = parent[cur];
      cycle.push_back(cur);
    }
    return;
  }

  parent[u] = p;
  visited[u] = '1';

  if(cycleFound)
    return;

  

  for(auto v:graph[u]){
    if(v == parent[u])
      continue;

    dfs(v, u, parent, visited, graph);
 
  }

  visited[u] = '2';
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int vertices, edges;
  cin>>vertices>>edges;
  vector<vector<int>> graph(vertices+1);
  for(int i=0; i<edges; i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<char> visited(vertices+1, '0');
  vector<int> parent(vertices+1);
  for(int i=1; i<=vertices; i++){
    if(visited[i] == '0'){
      dfs(i,i, parent, visited, graph);
    }
    if(cycleFound)
      break;
  }
  if(cycleFound){
    cout<<cycle.size()+1<<endl;
    for(auto x:cycle){
      cout<<x<<" ";
    }cout<<cycle[0]<<" ";
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
