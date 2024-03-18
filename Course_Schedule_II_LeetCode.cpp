#include <bits/stdc++.h> 
bool cyclic = false;

class Solution {
private:
void findIfCyclic(vector< vector<int>>& g, vector<int>& vis, vector<int>& curVis, int x){
    vis[x] = 1;
    curVis[x] = 1;
    if(cyclic) return;

    for(auto i : g[x]){
        if (curVis[i]) {
            cyclic = true;
            return;
        }

        if(!vis[i])
            findIfCyclic(g, vis, curVis, i);
    }

    curVis[x] = 0;
}

void topological_sort(vector< vector<int>>& g, vector<int>& v, int x, vector<int>& vis2){
    vis2[x] = 1;
    for(auto i : g[x]){
        if(!vis2[i]) topological_sort(g, v, i, vis2);
    }
    v.push_back(x);
}

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector< vector<int>> g(n);
        vector<int > vis(n, 0), vis2(n, 0), curVis(n,0), ans, v;

        for (auto i : prerequisites) 
            g[i[1]].push_back(i[0]);
        

        cyclic = false;
        for (int i = 0; i < n; i++) {

            if(!vis[i])
                findIfCyclic(g, vis, curVis, i);
        }
        
        if(cyclic) return ans;


        for(int i = 0; i < n; i++){
            if(!vis2[i])
                topological_sort(g, v, i, vis2);
        }

        for(int i = n-1; i >= 0; i--)
            ans.push_back(v[i]);

        return ans;
    }
};