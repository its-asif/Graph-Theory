

// bool dfs(int u,int par=0) {
//   vis[u] = true;

//   for (auto i: g[u]) {
//     if(vis[i] && i==par) continue;

    
//     dfs(i, u); 
//   }
// }


int main() {

  llt{

	int g[30][30] = {0};
	bool vis[30][30] ={0};

  	int n, m; cin >> n >> m;
  	vector<string> s(n);
	fi(n) cin>>s[i];

  	for (int i = 1; i <= n; ++i)
  	{
  		for (int j = 1; j <= m; ++j)
  		{
  			/* code */
  		}
  	}
  }


  // dfs(1);
  
  
  return 0;
}