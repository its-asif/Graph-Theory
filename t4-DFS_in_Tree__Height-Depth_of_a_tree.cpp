#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
// bool vis[N];  // no need of visited array for tree
int depth[N], height[N];

void dfs(int u,int par ) {
  // 
  for (auto i: g[u]) { 
    // 
    if (i==par) continue;
    depth[i] = depth[u]+1;
      dfs(i,u);  

    height[u] = max(height[u],height[i]+1);
    // 
  }

  // 
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n-1; ++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }


  dfs(1,0);
  
  for (int i = 1; i <= n; ++i)
  {
    cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
  }
  return 0;
}


/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11


ans:
0 4
1 3
1 3
2 2
2 2
3 0
3 0
3 1
3 0
3 1
4 0
4 0
1 0

*/