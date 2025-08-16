//  OJ          : Leetcode
//  Problem Name: Word Search
//  Problem Link: https://leetcode.com/problems/word-search/
    

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j){
        // pos - position of word & i,j - position of matrix
        int n = board.size();
        int m = board[0].size();
        if(pos == word.size()) return true;
        
        if(i < 0 
        or j < 0 
        or i >= n 
        or j >= m 
        or board[i][j] != word[pos]) return false;


        char tmp = board[i][j];
        board[i][j] = '#';
        if( dfs(board, word, pos+1, i+1, j) or 
            dfs(board, word, pos+1, i-1, j) or 
            dfs(board, word, pos+1, i, j+1) or 
            dfs(board, word, pos+1, i, j-1)) {
                return true;
            }

        board[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j=0; j < m; j++){
                if(dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};