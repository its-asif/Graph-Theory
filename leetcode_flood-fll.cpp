class Solution {
public:
    void dfs(int x,int y, int iniClr, int newClr,
     vector<vector<int>>& img){
        int n = img.size();
        int m = img[0].size();
        if(x<0 || y<0 || x>=n || y>=m || img[x][y] != iniClr) return;

        img[x][y]= newClr;

        dfs(x-1, y, iniClr, newClr, img);
        dfs(x+1, y, iniClr, newClr, img);
        dfs(x, y-1, iniClr, newClr, img);
        dfs(x, y+1, iniClr, newClr, img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {
        if(image[sr][sc] != color)
            dfs(sr,sc,image[sr][sc] , color, image);
        return image;
    }
};