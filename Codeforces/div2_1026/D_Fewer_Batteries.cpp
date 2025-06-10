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
    vector<int> b(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    vector<vector<pair<int,int>>> adjlist(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v,w});
    }
    // vector<bool> vis(n+1,0);
    auto dfs=[&](auto &&dfs,vector<int> &dp,int mid)->void
    {
        // vis[u]=1;
        for(int u=1;u<=n;u++)
        {
            dp[u]+=b[u];
            dp[u]=min(dp[u],mid);
            for(auto i:adjlist[u])
            {
                if(i.second>dp[u])
                {
                    continue;
                }
                dp[i.first]=max(dp[i.first],dp[u]);
            }
        }
    };
    int l=1,r=1e12,ans=1e12+5;
    while(l<=r)
    {
        int mid=(l+r)/2;
        vector<int> dp(n+1,-(1e12+5));
        // for(int i=1;i<=n;i++)
        // {
        //     vis[i]=0;
        // }
        dp[1]=0;
        dfs(dfs,dp,mid);
        if(dp[n]>0)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << (ans==1e12+5?-1:ans) << '\n';
}
signed main()
{
    fastio();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}