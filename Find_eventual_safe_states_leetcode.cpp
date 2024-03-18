//  OJ          : Leetcode
//  Problem Name: Find Eventual Safe States
//  Problem Link: https://leetcode.com/problems/find-eventual-safe-states/
    

class Solution {
private:
void dfs(vector< vector<int> >& g, vector<int>& inDeg, queue<int>& q, int x){

    for(auto i : g[x]){
        inDeg[i]--;
        if(!inDeg[i]) q.push(i);
    }
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector< vector<int> > g(n);
        vector<int> v, inDeg(n, 0); // v ->store answer
        queue<int> q;               // q -> store zero indegree
        for(int i=0; i<n; i++){
            for(auto j : graph[i]){
                g[j].push_back(i);
                inDeg[i]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!inDeg[i])
                q.push(i);
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();
            v.push_back(x);
            dfs(g, inDeg, q, x);
        }

        sort(v.begin(), v.end());

        return v;
    }
};