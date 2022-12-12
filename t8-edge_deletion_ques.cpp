#include<bits/stdc++.h>
using namespace std;
#define ll long long
 #define llt ll t; cin>>t; while(t--)

const int N = 1e5 + 9;
vector<int> g[N];
int subtree_sum[N];
int val[N];
const int M = 1e9+7;

void dfs(int v,int par ) {
  // 
	subtree_sum[v] += val[v];
  for (auto i: g[v]) { 
    // 
	if (i==par) continue;
	dfs(i,v); 
    //
    subtree_sum[v] += subtree_sum[i];
  }
  //
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int n; cin>>n;
	for (int i = 1; i <= n; ++i)
		cin>>val[i]; 
	for (int i = 0; i < n-1; ++i)
	{
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
    
    dfs(1,0);
    long long ans = 0;
 	for (int i = 2; i <= n; ++i)
 	{
 		int part1 = subtree_sum[i];
 		int part2 = subtree_sum[1] - part1;
 		// cout<<part1<<' '<<part2<<endl;
 		ans = max(ans, (part1* 1LL * part2) % M);
 	}
 	cout<<ans;
  return 0;
}