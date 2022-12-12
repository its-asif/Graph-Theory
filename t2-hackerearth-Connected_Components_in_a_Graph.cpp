#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;

  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v); 

    }

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

  int cnt=0;
  for (int i = 1; i <= n; ++i)
  {
    if(!vis[i]){ cnt++;
    dfs(i);}
  }
  
  cout<<cnt<<endl;
  
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

ans 3

*/