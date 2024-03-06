//	Coding Ninja
//	Problem Name: DFS Traversal
//	Problem Link: https://www.codingninjas.com/studio/problems/dfs-traversal_630462

void dfs(int n, vector<vector<int>>& g, int vis[], vector<int> &v){
    vis[n] = 1;
    v.push_back(n);
    for(int i : g[n]){
      if(vis[i] == 0) dfs(i, g, vis, v);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){

	int vis[V] = {0};
	vector<vector<int>> g(V);
	vector<vector<int>> ans;
	int cnt = 0;

	for(auto i : edges){
	  g[i[0]].push_back(i[1]);
	  g[i[1]].push_back(i[0]);
	}

	for(int i =0; i < V; i++){
      if(vis[i] == 0) {
          vector<int> x;
          dfs(i, g, vis, x);
          ans.push_back(x);
      }
	}

    // cout << ans.size() << endl;
    return ans;
}