#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
bool vis2[N];
int x=-1,y=0;
vector<int> v;

bool dfs(int u,int par) {
  vis[u] = true;
  bool loop = false;
  for (auto i: g[u]) {
    if(vis[i] && i==par) continue;
	if(vis[i]) return true; 
    
    dfs(i, u); 
  }
}

void dfs2(int u,int par=-1) {
	if(y==-2) return;
  vis2[u]=true;
  v.push_back(u);
  for(auto i:g[u]){
  	if(vis2[i] && par==i) continue;
  	if(vis2[i]) {y=-2;return;}
  	dfs2(i,u);
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
  		x=i;
  		loop= true;
  		break;
  	}
  }
  
  if(loop){
  	dfs2(x);
  	v.push_back(x);
  	cout<<v.size()<<endl;
  	for (int i = 0; i < v.size(); ++i)
  	{
  		cout<<v[i]<<' ';
  	}
  }
  else cout<<"IMPOSSIBLE" <<endl;
  return 0;
}
