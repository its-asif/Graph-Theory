//  OJ          : Leetcode
//  Problem Name: Number of Islands
//  Problem Link: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void arekta_island(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i< 0 or j < 0 or i >= n or j >= m or grid[i][j] == '0') return;

        // vis[i][j] = true;
        grid[i][j] = '0';
        arekta_island(grid, i+1, j, n, m);
        arekta_island(grid, i, j+1, n, m);
        arekta_island(grid, i, j-1, n, m);
        arekta_island(grid, i-1, j, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( grid[i][j] == '1') {
                    cnt++;
                    arekta_island(grid, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};