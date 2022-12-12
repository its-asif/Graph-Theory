#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int len[N],mxlen=0;

void dfs(int u,int par=0) {
  // 
  vis[u]= true;

 len[u] = len[par]+1;
 cout<<len[u]<<' '<<u<<' '<<par<<endl;
 mxlen = max(mxlen,len[u]);


  for (auto i: g[u]) { 
    
    if (vis[i]) continue;
    dfs(i,u); 

  }
}
  


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v;

  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    if(u==-1) {v.push_back(i);}
    g[u].push_back(i);
    g[i].push_back(u);
  }

  
    for (auto i:v)
  {
    dfs(i);
  }
  

  
  cout<<mxlen<<endl;
  return 0;
}