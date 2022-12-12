#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long

const ll N = 1e5 + 9;
vector<ll> g[N];
bool vis[N];
ll depth[N];
double ans=0,sub[N];

void dfs(ll x,ll par=0){

  for(auto i: g[x]){
    if(i==par) continue;
    depth[i] += depth[x]+1;
    if(x==1 || g[x].size()==1) sub[i]= (sub[x]*1.0)/ g[x].size();
    else sub[i]= (sub[x]*1.0)/ (g[x].size()-1);
    // cout<<i<<' '<<sub[i]<<' '<<sub[x]<<' '<<g[x].size()<<endl;
    
    dfs(i,x);
    if(g[i].size()==1){
    	ans += sub[i]*depth[i];
    }
  }
}
 

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin>>n;
  for (ll i = 0; i < n-1; ++i)
  {
  	ll x,y; cin>>x>>y;
  	g[x].push_back(y);
  	g[y].push_back(x);
  }

  sub[1]= 1;
  dfs(1);

  cout << setprecision (15) << fixed << ans;

}

