//and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
 
//constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const char dir[4]{'D','R','U','L'};
const int MOD=1e9+7;
const int maxn=2e5+5;
const double eps=1e-9;
 
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
//Mods
int add(int a, int b) 
{
    if((a+=b)>=MOD)
    {
        a-=MOD;
    }
    return a;
}
int sub(int a, int b) 
{
  if((a-=b)<0)
  {
        a+=MOD;
  }
  return a;
}
int mul(int a,int b) 
{
    int ret=(a%MOD*b%MOD)%MOD;
    if(ret<0)
    {
        ret+=MOD;
    }
    return ret;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adjlist(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    vector<int> vis(n+5,0);
    vector<vector<int>> mn(n+5);
    mn[1].push_back(0);
    vector<map<int,int>> mp(n+1);
    mp[1][0]++;
    auto dfs=[&](auto &&dfs,int u)->void
    {
        vis[u]=1;
        // if(u==v)
        // {
        //     return;
        // }
        for(auto i:adjlist[u])
        {
            if(not vis[i.first])
            {
                for(int uu=0;uu<=2048;uu++)
                {
                    if(mp[u][uu])
                    {
                        mp[i.first][uu^i.second]++;
                    }
                }
                dfs(dfs,i.first);
            }
            else
            {
                for(int uu=0;uu<=2048;uu++)
                {
                    if(mp[u][uu])
                    {
                        mp[i.first][uu^i.second]++;
                    }
                }
            }
        }
    };
    int ans=LLONG_MAX;
    // for(int i=2;i<=n;i++)
    // {
    //     mn[1]=0;
    //     for(int j=2;j<=n;j++)
    //     {
    //         mn[j]=1e9;
    //     }
    //     dfs(dfs,1,i);
    //     for(int j=i;j<=n;j++)
    //     {
    //         dfs(dfs,j);
    //     }
    //     ans=min(ans,mn[n]);
    //     debug(mn[n])
    // }
    dfs(dfs,1);
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    dfs(dfs,n);
    // for(auto i:mn[n])
    // {
    //     cerr << i << '\n';
    // }
    for(auto [key,val]:mp[n])
    {
        // debug(mp[n][key])
        if(mp[n][key])
        {
            ans=min(ans,key);
        }
    }
    if(ans==LLONG_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << '\n';
    }
}
signed main()
{
    fastio();
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}