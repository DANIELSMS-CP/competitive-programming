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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    vector<vector<pair<int,int>>> adjlist(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    int ans=0;
    vector<int> subtree_size(n+1,0);
    auto dfs=[&](int u,int v,auto &&dfs)->int
    {
        int szz=a[u];
        if(sz(adjlist[u])==1 and u!=1)
        {
            return subtree_size[u]=a[u];
        }
        for(auto i:adjlist[u])
        {
            if(i.first!=v)
            {
                szz+=dfs(i.first,u,dfs);
            }
        }
        for(auto i:adjlist[u])
        {
            if(i.first!=v)
            {
                ans+=abs(subtree_size[i.first]*i.second);
            }
        }
        return subtree_size[u]=szz;
    };
    dfs(1,1,dfs);
    cout << ans << '\n';
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
// 0+-12+-6*1+-12+