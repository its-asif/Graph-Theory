#include<bits/stdc++.h>
using namespace std;

/* ques:
Given Q Queries, Q <= 10^5
In each query given V,
Print subtree sum of V in subtree V

*/
const int N = 1e5 + 9;
vector<int> g[N];
int subSum[N];

void dfs(int u,int par ) {
  // 
  subSum[u] = u;
  for (auto v: g[u]) { 
    // 
    if (v==par) continue;
      dfs(v,u); 

    subSum[u] += subSum[v];
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
    cout<<subSum[i]<<endl;
  }
  return 0;
}