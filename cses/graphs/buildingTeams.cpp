/*
  Concept - Bipartite Graph
  Alogrithm Used - Coloring Scheme to check Bipartiteness of the graph
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  int vertices,edges;
  cin>>vertices>>edges;
  vector<vector<int>> graph(vertices+1);
  for(int i=0; i<edges; i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  vector<int> color(vertices+1);
  vector<bool> visited(vertices+1);
  
  for(int i=1; i<=vertices; i++){
      if(!visited[i]){
        color[i] = 1;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
          int u = q.front();
          q.pop();
          int curColor = color[u] == 1 ? 2 : 1;
          for(auto v : graph[u]){
            if(!visited[v]){
              visited[v] = true;
              color[v] = curColor;
              q.push(v);
            }else if(color[v] != 0 && color[v] != curColor){
              cout<<"IMPOSSIBLE"<<endl;
              return 0;
            }
          }
        }
      }     
  }
  for(int i=1; i<=vertices; i++)
    cout<<color[i]<<" ";
  cout<<endl;
  return 0;
}
