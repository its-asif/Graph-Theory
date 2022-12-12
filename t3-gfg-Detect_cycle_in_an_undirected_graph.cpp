//problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//tutorial link: https://youtu.be/zBbRgLpeZus?t=756

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

bool dfs(int u,int par) {
  vis[u] = true;
  bool loop = false;
  for (auto i: g[u]) {
    if(vis[i] && i==par) continue;
    if(vis[i]) return true; 
    
    dfs(i, u); 
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }


  bool loop = false;
  for (int i = 1; i <= n; ++i)
  {
  	if(vis[i]) continue;
  	if(dfs(i,0)){
  		loop= true;
  		break;
  	}
  }
  
  if(loop) cout<<"there exists a loop"<<endl;
  else cout<<"there is no loop" <<endl;
  return 0;
}


/*
for 

8 5
1 2
2 3
2 4
3 5
6 7

ans: there is no loop;


for
8 6
1 2
2 3
2 4
3 5
6 7
1 5

ans: there exists a loop;

*/
