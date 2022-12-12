#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long

const ll N = 1e5 + 9;
vector<ll> g[N];
bool vis[N];
ll depth[N],mxdepth=0;

void dfs(ll x,ll par=0){


  for(auto i: g[x]){
    if(i==par) continue;
    depth[i] += depth[x]+1;
    mxdepth = max(mxdepth,depth[i]);
    dfs(i,x);
    // sub[x] += sub[i]+1;

  }

}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin>>n;
  map<string, ll> mp;
  mp["polycarp"]=1;
  int cnt=1;
  for (ll i = 0; i < n; ++i)
  {
    string s,x,y; 
    cin>>x>>s>>y;
    cnt++;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(y.begin(), y.end(), y.begin(), ::tolower);
    mp[x]=cnt;
    g[mp[x]].push_back(mp[y]);
    g[mp[y]].push_back(mp[x]);
    // cout<<mp[x]<<' '<<mp[y]<<endl;
  }

  dfs(1);

  cout<<mxdepth+1;
}