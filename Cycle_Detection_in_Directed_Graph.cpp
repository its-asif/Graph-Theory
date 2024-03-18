//  OJ          : Coding Ninja
//  Problem Name: Detect Cycle In A Directed Graph
//  Problem Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626



bool bb = false;

void dfs(vector< vector<int>>& g, int vis[], int curVis[], int x){
    vis[x] = 1;
    curVis[x] = 1;
    if(bb) return;

    for(auto i : g[x]){
    	 if(curVis[i]){
            bb = true;
            return;
        }

        if(!vis[i])
            dfs(g, vis, curVis, i);
    }

    curVis[x] = 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector< vector<int> > g(n+1);
    int vis[n+1] = {0};
    int curVis[n+1] = {0};
    for(auto i : edges){
      g[i.first].push_back(i.second);
    }

      bb = false;
    for(int i = 1; i<=n ; i++){
      if(!vis[i])
          dfs(g, vis, curVis, i);
    }

    return bb;
}