//  OJ          : Coding Ninja
//  Problem Name: Khan's Algorithm (Topological Sorting)
//  Problem Link: https://www.codingninjas.com/studio/problems/topological-sorting_973003

#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
        
           vector<int> ans, indeg(nodes, 0);
            queue<int> q;
           vector<vector<int>> g(nodes);
            for(auto i : graph){
                g[i[0]].push_back(i[1]);
                indeg[i[1]]++;
            }

            for(int i = 0; i < nodes; i++){
                if(indeg[i] == 0) q.push(i); 
            }
            
            while(!q.empty()){
                int x = q.front();
                ans.push_back(x);
                q.pop();
                for(auto i : g[x]){
                    indeg[i]--;
                    if(indeg[i] == 0) q.push(i);
                }
            }

           return ans;
}
