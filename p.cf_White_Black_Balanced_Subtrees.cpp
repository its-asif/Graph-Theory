#include<bits/stdc++.h>
using namespace std;
#define ll long long
 #define llt ll t; cin>>t; while(t--)

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> sub(N);
vector<int> viscnt(N);
int cnt=0;

void dfs(int u,int par ) {
  // 
  for (auto v: g[u]) { 
    // 
    if (v==par) continue;
    viscnt[u]++;
      dfs(v,u); 

    sub[u] += sub[v];
    if(sub[u]==0 && viscnt[u]==g[u].size()-1) {cnt++;
      // cout<<u<< ' '<< viscnt[u]<<' '<<g[u].size()-1<<endl;
    }
    else if(sub[u]==0 && viscnt[u]==g[u].size() && u==1) cnt++;
    //
  }
  //
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

 llt{
   int n; cin >> n;
   for (int i = 2; i <= n; ++i){
      int u; cin >> u;
      g[u].push_back(i);
      g[i].push_back(u);
    }
    string s; cin>>s;
    for (int i = 0; i < n; ++i)
    {
      if(s[i]=='W') sub[i+1]= 1;
      else sub[i+1] = -1;
    }

    dfs(1,0);
    
    cout<<cnt<<endl;
    // for (int i = 1; i <= n; ++i) cout<<viscnt[i]<<' ';cout<<endl;
    cnt=0;
    //viscnt.clear();
    for (int i = 0; i <= n; ++i) viscnt[i]=0;
    sub.clear();
    
    for (int i = 0; i <= n; ++i)
    {
      g[i].clear();
    }
 }
  return 0;
}