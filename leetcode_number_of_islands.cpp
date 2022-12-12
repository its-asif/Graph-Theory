class Solution {
public:
    int cnt=0;
    void dfs(int x,int y,
     vector<vector<char>>& grd,vector<vector<int>>& vis){
        int n = grd.size();
        int m = grd[0].size();
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || grd[x][y]=='0') return;

        vis[x][y]= 1;

        dfs(x-1, y, grd,vis);
        dfs(x+1, y, grd,vis);
        dfs(x, y-1, grd,vis);
        dfs(x, y+1, grd,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nn = grid.size(), mm = grid[0].size();
        vector<vector<int>> vis(nn, vector<int>(mm, 0));
        for (int i = 0; i < nn; ++i)
        {
            for (int j = 0; j < mm; ++j)
            {
                if(!vis[i][j] && grid[i][j]!='0')
                {
                    dfs(i,j,grid ,vis);
                    //cout<<i<<' '<<j<<endl;
                    cnt++;
                }
                // cout<<vis[i][j]<<' ';
            }//cout<<endl;
        }
        return cnt;
    }
};