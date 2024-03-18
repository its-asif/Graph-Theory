//  OJ          : Coding Ninja
//  Problem Name: Course Schedule
//  Problem Link: https://www.codingninjas.com/studio/problems/course-schedule_985288

#include <bits/stdc++.h> 

bool cyclic = false;

void dfs(vector< vector<int>>& g, int vis[], int curVis[], int x){
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


string canFinish(vector<vector<int>>& prerequisites, int n, int m)
{
    vector< vector<int>> g(n+1);
    int vis[n+1] = {0};
    int curVis[n+1] = {0};

    for (auto i : prerequisites) 
        g[i[1]].push_back(i[0]);
    

    cyclic = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(g, vis, curVis, i);
        if (cyclic) break;
    }

    if(cyclic) return "No";
    return "Yes";
}
