#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  // take action on vertex 
  // after entering the vertex
  vis[u] = true;

  for (auto v: g[u]) {
    // take action on child
    // before entering the child node
    if (!vis[v]) {
      dfs(v); 

      // take action on child 
      // after exiting child node
    }

    // take action on vertex
    // before exiting the vertex
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


  dfs(1);
  
  
  return 0;
}