//	Coding Ninja
//	Problem Name: BFS in Graph
//	Problem Link: https://www.codingninjas.com/studio/problems/bfs-in-graph_973002

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> v;
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        v.push_back(x);
        for(int i : adj[x]){
            if(vis[i] == 0) q.push(i);
            vis[i] = 1;
        }
    }
    return v;
}