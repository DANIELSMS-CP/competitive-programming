// 道草を楽しめ 大いにな。ほしいものより大切なものが きっとそっちに ころがってる
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);

//constants
const int maxn = 2e5 + 5;
const int LOG = 20;
const int INF = 1e18;

//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi g[maxn];

// LCA
int dep[maxn];
int up[maxn][LOG];

// centroid decomposition
int sub[maxn];
int cpar[maxn];
bool dead[maxn];

// problem-specific
int best[maxn];

void dfs_lca(int u, int p)
{
    up[u][0] = p;

    for(int j = 1; j < LOG; j++)
        up[u][j] = up[up[u][j - 1]][j - 1];

    for(int v : g[u])
    {
        if(v == p) continue;

        dep[v] = dep[u] + 1;
        dfs_lca(v, u);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v])
        swap(u, v);

    int d = dep[u] - dep[v];

    for(int j = 0; j < LOG; j++)
    {
        if(d & (1LL << j))
            u = up[u][j];
    }

    if(u == v)
        return u;

    for(int j = LOG - 1; j >= 0; j--)
    {
        if(up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int dist(int u, int v)
{
    int w = lca(u, v);

    return dep[u] + dep[v] - 2 * dep[w];
}

void dfs_sz(int u, int p)
{
    sub[u] = 1;

    for(int v : g[u])
    {
        if(v == p || dead[v]) continue;

        dfs_sz(v, u);
        sub[u] += sub[v];
    }
}

int get_centroid(int u, int p, int tot)
{
    for(int v : g[u])
    {
        if(v == p || dead[v]) continue;

        if(sub[v] > tot / 2)
            return get_centroid(v, u, tot);
    }

    return u;
}

void build_centroid(int u, int p = -1)
{
    dfs_sz(u, -1);

    int c = get_centroid(u, -1, sub[u]);

    cpar[c] = p;
    dead[c] = true;

    for(int v : g[c])
    {
        if(dead[v]) continue;

        build_centroid(v, c);
    }
}

void update(int v)
{
    int cur = v;

    while(cur != -1)
    {
        best[cur] = min(best[cur], dist(v, cur));
        cur = cpar[cur];
    }
}

int query(int v)
{
    int ans = INF;

    int cur = v;

    while(cur != -1)
    {
        ans = min(ans, dist(v, cur) + best[cur]);
        cur = cpar[cur];
    }

    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    rep(i,0,n-1)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dep[1] = 0;
    dfs_lca(1, 1);

    fill(cpar, cpar + n + 1, -1);
    build_centroid(1);

    fill(best, best + n + 1, INF);

    update(1);

    while(m--)
    {
        int t, v;
        cin >> t >> v;

        if(t == 1)
            update(v);
        else
            cout << query(v) << '\n';
    }
}

signed main()
{
    fastio();

    solve();

    return 0;
}