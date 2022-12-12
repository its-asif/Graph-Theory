#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long

const ll N = 1e6 + 9;
vector<ll> g[N];
bool vis[N];
ll sub[N],depth[N],ans[N];

void dfs(ll x,ll par=0){


	for(auto i: g[x]){
		if(i==par) continue;
		depth[i] += depth[x]+1;
		dfs(i,x);
		sub[x] += sub[i]+1;

	}

}


int main(){
	ios_base::sync_with_stdio(0);
  	cin.tie(0);

	ll n,m; cin>>n>>m;
	for (ll i = 0; i < n-1; ++i)
	{
		ll x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		
	}

	dfs(1);

	ll v[n];
	for (ll i = 0; i < n; ++i)
	{
		v[i] = depth[i+1]-sub[i+1];
	}

	sort(v,v+n,greater<ll>());

	ll slv=0;

	for (ll i = 0; i < m; ++i)
	{
		slv += v[i];
	}

	cout<<slv;
}