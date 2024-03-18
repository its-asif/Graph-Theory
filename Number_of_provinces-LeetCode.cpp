//  Leetcode
//  Problem Name: Number of Provinces
//  Problem Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
private:
    void dfs(int n, vector<vector<int>>& g, vector<bool>& vis){
    vis[n] = 1;
    for(auto i : g[n]){
        if(!vis[i]) dfs(i, g, vis);
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n);
        int cnt = 0; 
        vector<vector<int>> g(n);
        for(int i =0; i < n; i++){          // O(n^2)
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 and i != j){
                    g[i].push_back(j);
                }
            }
        }


        for(int i =0; i<n; i++){            // O(n)
            if(!vis[i]){
                cnt++;
                dfs(i, g, vis);
            }
        }

        return cnt ;
        }
};