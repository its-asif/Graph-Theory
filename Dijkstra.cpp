//find sortest path of all nodes from one source
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+10;
const int INF = 1e9+10;
vector<int> vis(N,0);
vector<int> dist(N,INF);

vector<pair<int,int>> g[N];

void dijkstra(int source){

	set<pair<int,int>>st;
	st.insert({0,source}); // (0,1)
	dist[source]=0;

	while(st.size()>0){
		auto node = *st.begin(); // (0,1) / (1,2) ->(node,distance)
		int v = node.second;     //   1   /   2
		int v_dist = node.first; //	  0   /   1
		st.erase(st.begin());    
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto i : g[v]){      // v=2  -> g[v] = (3,2),(4,2),(5,1)
			int child_v = i.first;	// 3,4,5
			int wt = i.second;		// 2,2,1
			if(dist[v]+wt < dist[child_v]){
				dist[child_v] =dist[v] +wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}
}

int main(){
	int n,m; cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int x,y,wt;
		cin>>x>>y>>wt;
		g[x].pb({y,wt});
		// cout<<y<<' '<<wt<<endl;
	}
	dijkstra(1);

	for (int i = 1; i < n+1; ++i)
	{
		cout<<i<<' '<<dist[i]<<endl;
	}

}


/*

6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2

		2----4
	   /|\   |\
	  /	|	 | \
	 1  |  \ |	6
	  \	|	 | /
	   \|	\|/
	    3----5
*/