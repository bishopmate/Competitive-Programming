#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
*/

class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
      parent.resize(n+1);
      size.resize(n+1);
    }

    int find_set(int a){
        while(parent[a] != a){
          a = parent[a];
        }
        return a;
    }
    
    void make_set_by_size(int v){
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets_by_size(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];

        }
    }

};

struct Edges{
  int u,v,weight;
  bool operator<(Edges const& partner){
    return weight <= partner.weight;
  }
};

signed main(){
  int n,m;
  cin>>n>>m;
  vector<Edges> edges;
  for(int i=0; i<m; i++){
    Edges e;
    cin>>e.u>>e.v>>e.weight;
    edges.push_back(e);
  }
  DSU tree(n);
  for(int i=1; i<=n; i++){
    tree.make_set_by_size(i);
  }
  sort(edges.begin(), edges.end());
  int edgesInMST = 0;
  int i = 0;
  int costMST = 0;
  while(i < m && edgesInMST < (n-1)){
    int u = edges[i].u;
    int v = edges[i].v;
    int uGroup = tree.find_set(u), vGroup = tree.find_set(v);
    if(uGroup != vGroup){
      tree.union_sets_by_size(u,v);
      costMST = costMST + edges[i].weight;
      edgesInMST++;
    }
    i++; 
  }
  if(edgesInMST < (n-1)){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<costMST<<endl;
  }
  return 0;
}