#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];

int vis[N];
int level[N];

void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] =1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i: g[x]){
			if(vis[i]==false){
				q.push(i);
				vis[i] = 1;
				level[i] = level[x] +1;
			}
		}
	}
}

int main(){
	int n; cin>>n;

	for (int i = 0; i < n-1 ; ++i)
	{
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1);

	for (int i = 1; i <= n; ++i)
	{
		cout<< i << ":" << level[i] << endl;
	}
}