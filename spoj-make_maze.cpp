#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define fi(n) for(ll i=0; i<n; i++)
#define fj(n) for(ll j=0; j<n; j++)
#define rfi(n) for(ll i = n-1; i >=0; --i)
#define fa(n) for(auto i:n)
#define fa2(n) for(auto i:n) cout<<i<<' ';
#define llt ll t; cin>>t; while(t--)
#define lln ll n; cin>>n;
#define llnm ll n,m; cin>>n>>m;
#define llx ll x; cin>>x;
#define llxy ll x,y; cin>>x>>y;
#define llab ll a,b; cin>>a>>b;

#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define pbx ll xx; cin>> xx; v.pb(xx);
#define pbs string xx; cin>> xx; v.pb(xx);
#define all(x) x.begin(), x.end()
#define srt(x) sort(all(x))
#define rsrt(x) sort(all(x),greater<ll>())
#define veccin(n) vll v(n); fi(n) cin>>v[i];

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/__gcd(a,b)))

#define endl "\n"
#define nl <<endl
#define sp <<' '
#define sps <<' '<<
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define C(x) cout<< x <<endl;
#define F i.first
#define S i.second

void dfs(int i,int j,int n,int m,vector<string>& v,vector<vector<int>>& vis,int &cnt)
{
  if(i<0 || j<0 || i>n || j>m || vis[i][j] || v[i][j]=='#') return;

  vis[i][j]=1;
  if(i==0 || i==n-1 || j==0 || j==n-1) cnt++;
  dfs(i+1, j, n, m, v, vis, cnt);
  dfs(i-1, j, n, m, v, vis, cnt);
  dfs(i, j+1, n, m, v, vis, cnt);
  dfs(i, j-1, n, m, v, vis, cnt);
}

int main() {

  llt{

	vector<vector<int>> vis(30, vector<int>(30, 0));

  	int n, m; cin >> n >> m;
  	vector<string> s(n);
    fi(n) cin>>s[i];
    bool temp;
    int sideCnt =0;
    for (int i = 0; i < n; ++i)
    {
      if(s[i][0]=='.') sideCnt++;
      if(s[i][m-1]=='.' && m-1!=0) sideCnt++;
    }
    for (int i = 1; i < n-1; ++i)
    {
      if(s[0][i]=='.') sideCnt++;
      if(s[n-1][i]=='.' && n-1!=0) sideCnt++;
    }

    if(sideCnt!=2){
      C("invalid")
      continue;
    }

  	for (int i = 0; i < n; ++i)
  	{
      temp=false;
  		for (int j = 0; j < m; ++j)
  		{ 
         int cnt=0;
  			 if(s[i][j]=='.' && !vis[i][j])
              dfs(i,j,n-1,m-1,s,vis,cnt);
          

          if(cnt==2){
            temp=true;
            break;
          }
  		}
      if(temp) break;
  	}


  if(temp) cout<<"valid" nl;
  else cout<<"invalid" nl;


  }

  return 0;
}