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
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> adjlist(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<map<int,int>> mp(n);
    vector<int> ans(n);
    auto dfs=[&](auto &&dfs,int u,int v)->void
    {
        mp[u][a[u]]++;
        int ssz=sz(mp[u]),sssz=sz(adjlist[u]),mx=u;
        if(sssz==1 and u!=0)
        {
            ans[u]=sz(mp[u]);
            return;
        }
        for(auto i:adjlist[u])
        {
            if(i!=v)
            {
                dfs(dfs,i,u);
                if(ssz<sz(mp[i]))
                {
                    ssz=sz(mp[i]);
                    mx=i;
                }
            }
        }
        mp[u].swap(mp[mx]);
        for(auto i:adjlist[u])
        {
            if(i!=v)
            {
                for(auto [key,val]:mp[i])
                {
                    mp[u][key]+=mp[i][key];
                }
            }
        }
        ans[u]=sz(mp[u]);
    };
    dfs(dfs,0,0);
    for(int i=0;i<n;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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