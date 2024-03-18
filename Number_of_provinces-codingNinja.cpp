//	Coding Ninja
//	Problem Name: Find the Number of Provinces
//	Problem Link: https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943

void dfs(int n, vector<unordered_set<int>>& g, int vis[]) {
    vis[n] = 1;
    for (auto i : g[n]) {
        if (!vis[i]) dfs(i, g, vis);
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int vis[n] = {0};
    int cnt = 0; 
    vector<unordered_set<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (roads[i][j] == 1) {
                g[i].insert(j);
                g[j].insert(i); // Since it's an undirected graph
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, g, vis);
        }
    }

    return cnt;
}
