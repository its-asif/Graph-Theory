#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int par[N];

void dfs(int v,int p=0){
	par[v] = p;
	for (int i: g[v])
	{
		if(i == p) continue;
		dfs(i,v);
	}
}

vector<int> path(int v){
	vector<int> ans;
	while(v != 0){
		ans.push_back(v);
		v = par[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	int n; cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);
	int x,y; cin>>x>>y;
	vector<int> path_x = path(x);
	vector<int> path_y = path(y);
	int mn_length = min(path_x.size(),path_y.size());

	int lca =-1;
	for (int i = 0; i < mn_length; ++i)
	{
		if (path_x[i]==path_y[i])
		{
			lca= path_x[i];
		}
		else break;
	}


	cout<<lca<<endl;
}


/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11


&
for 7 2
ans: 2

for 6 7
ans: 5
*/