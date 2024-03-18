//	OJ			: Leetcode
//	Problem Name: Course Schedule
//	Problem Link: https://leetcode.com/problems/course-schedule/
	

#include <bits/stdc++.h> 
bool cyclic = false;

class Solution {
private:
void dfs(vector< vector<int>>& g, vector<int>& vis, vector<int>& curVis, int x){
        vis[x] = 1;
        curVis[x] = 1;
        if(cyclic) return;

        for(auto i : g[x]){
            if (curVis[i]) {
                cyclic = true;
                return;
            }

            if (!vis[i])
            dfs(g, vis, curVis, i);
        }

        curVis[x] = 0;
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector< vector<int>> g(n+1);
        vector<int > vis(n, 0), curVis(n,0);

        for (auto i : prerequisites) 
            g[i[1]].push_back(i[0]);
        

        cyclic = false;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(g, vis, curVis, i);
            if (cyclic) break;
        }

        if(cyclic) return false;
        return true;
    }
};