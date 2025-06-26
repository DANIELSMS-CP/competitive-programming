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
    int n,a,b;
    cin >> n >> a >> b;
    vector<vector<int>> adjlist(n+1);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    if(a==b)
    {
        cout << "NO\n";
        return;
    }
    vector<bool> vis(n+1,0),cycle(n+1,0);
    vector<int> dista(n+1,LLONG_MAX),distb(n+1,LLONG_MAX);
    auto dfs=[&](auto &&dfs,int u,int v)->bool
    {
        vis[u]=1;
        for(auto i:adjlist[u])
        {
            if(i!=v)
            {
                if(vis[i] or dfs(dfs,i,u))
                {
                    return cycle[u]=1;
                }
            }
        }
        return false;
    };
    auto bfs=[&](int start,vector<int> &dist)->void
    {
        vector<bool> vist(n+1,0);
        queue<int> q;
        dist[start]=0;
        q.push(start);
        vist[start]=1;
        while(not q.empty())
        {
            int fr=q.front();
            q.pop();
            for(auto i:adjlist[fr])
            {
                if(not vist[i])
                {
                    vist[i]=1;
                    dist[i]=dist[fr]+1;
                    q.push(i);
                }
            }
        }
    };
    dfs(dfs,1,1);
    bfs(a,dista);
    bfs(b,distb);
    for(int i=1;i<=n;i++)
    {
        if(cycle[i] and dista[i]>distb[i])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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