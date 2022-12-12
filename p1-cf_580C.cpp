#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int cSum[N];
int cnt=0;
int cat[N];

void dfs(int u,int par,int m) {
  // 
  if(cat[u]==0) cSum[u] = 0;
  else cSum[u] = cSum[par] + 1;

  if(cSum[u]>m) return;

  for (auto i: g[u]) { 
    // 
    if (i==par) continue;
      dfs(i,u,m); 

      if(g[i].size()==1 && cSum[i]<=m) {cnt++;}

    //
  }
}
  


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {int x;cin>>x; cat[i]=x;}

  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1,0,m);
  
  cout<<cnt<<endl;
  return 0;
}