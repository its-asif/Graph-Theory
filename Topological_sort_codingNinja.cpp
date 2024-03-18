//  Coding Ninja
//  Problem Name: Topological Sorting
//  Problem Link: https://www.codingninjas.com/studio/problems/topological-sorting_973003


void dfs(vector<vector<int>>& g, vector<int>& ans , int x, int vis[]){
    vis[x] = 1; 
    for(auto i : g[x]){
        if(!vis[i]){
            dfs(g, ans, i, vis);
        }
    }

    ans.push_back(x);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
        
           vector<int> ans,v;
            int vis[nodes] = {0};
           vector<vector<int>> g(nodes);
            for(auto i : graph){
                g[i[0]].push_back(i[1]);
            }

            for(int i = 0; i < nodes; i++){
                if(!vis[i]){
                    dfs(g, ans, i, vis);
                }
            }            
            
            for(int i = nodes-1; i>=0; i--){
                v.push_back(ans[i]);
            }

                      
           return v;
}
