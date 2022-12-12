#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long

const ll N = 1e4 + 9;
vector<ll> g[N];
ll subsum[N],cnt=0;

void dfs(ll x,ll par=0){


  for(auto i: g[x]){

    if(i==par) continue;
    dfs(i,x);

    subsum[x] += subsum[i];

  }

  if(subsum[x]==0) cnt++;
}
 

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin>>t; 
  while(t--){
    ll n; cin>>n;
    for (ll i = 2; i <= n; ++i)
    {
      ll x; cin>>x;
      g[x].push_back(i);
      g[i].push_back(x);
    }
    string s; cin>>s;

    for (int i = 0; i < s.size(); ++i)
    {
      if(s[i]=='W') subsum[i+1] = 1;
      else subsum[i+1]= -1;
    }

    dfs(1);

    cout<<cnt<<endl;
    cnt=0;
    for (int i = 0; i <= n+9; ++i)
    {
      g[i].clear();
      subsum[i] =0;
    }
  }

}

