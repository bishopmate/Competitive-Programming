#include<bits/stdc++.h>
using namespace std;
int main(){
   
  int n;
  cin>>n;
  vector<pair<int, int>> v(n);
  multiset<pair<int, int>> s;   

  for(int i=1; i<=n; i++){
      int x,y;
      cin>>x>>y;
      s.insert(make_pair(x,i*-1));
      s.insert(make_pair(y,i));
  }
  
  sort(v.begin(), v.end());
  queue<int> vacantRooms;
  set<int> occupiedRooms;
  int roomsInUse = 0;
  int ans[n+1];
  while(!s.empty()){
      pair<int, int> top = *(s.begin());
      if(top.second < 0){
          int x = top.second*-1LL;
          if(vacantRooms.empty()){
              ++roomsInUse;
              ans[x] = roomsInUse;
          }else{
              ans[x] = vacantRooms.front();
              vacantRooms.pop();
          }
          occupiedRooms.insert(ans[x]);
      }else{
          int room = ans[top.second];
          auto it = occupiedRooms.find(room);
          vacantRooms.push(room);
          occupiedRooms.erase(it);
      }
      s.erase(s.begin());
  }
  cout<<roomsInUse<<endl;
  for(int i=1; i<=n; i++){
      cout<<ans[i]<<" ";
  }
  return 0;
}
