//  OJ          : Leetcode
//  Problem Name: Is Graph Bipartite?
//  Problem Link: https://leetcode.com/problems/is-graph-bipartite/
    

class Solution {
public:
    bool colorGraph(vector<vector<int>>& graph, int n, vector<int>& color,int i, int expected){
        if( i == n or color[i] == expected ) return true;
        if( color[i] != expected and color[i] != 0) return false;
        color[i] = expected;
        int nextColor = expected * -1;
        
        for(auto x : graph[i]){
            if( colorGraph(graph, n, color, x, nextColor ) == false){
                return false;
            } 
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i = 0; i < n; i++){
            if( color[i] == 0 and colorGraph(graph, n, color, i, 1) == false){
                return false;
            }
        }

        return true;
    }
};