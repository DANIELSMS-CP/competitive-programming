// 道草を楽しめ 大いにな。ほしいものより大切なものが きっとそっちに ころがってる
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets
 
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
const int maxn=2e5+5;
const double eps=1e-9;
 
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <typename T, auto M> struct Mod {
    using V = conditional_t<sizeof(T) <= 4, u64, u128>;
    static V inv(V x, V m) { return x > 1 ? m - inv(m % x, x) * m / x : 1; }
    make_unsigned_t<T> x;
    Mod() : x(0) {}
    Mod(auto y) : x(y % M) { x >= M ? x += M : x; }
    operator T() const { return x; }
    Mod operator-() const { return Mod() -= *this; }
    Mod operator+(auto rhs) const { return Mod(*this) += rhs; }
    Mod operator-(auto rhs) const { return Mod(*this) -= rhs; }
    Mod operator*(auto rhs) const { return Mod(*this) *= rhs; }
    Mod operator/(auto rhs) const { return Mod(*this) /= rhs; }
    Mod &operator+=(Mod rhs) { return (x += rhs.x) >= M ? x -= M : x, *this; }
    Mod &operator-=(Mod rhs) { return (x -= rhs.x) >= M ? x += M : x, *this; }
    Mod &operator*=(Mod rhs) { return x = x * V(rhs.x) % M, *this; }
    Mod &operator/=(Mod rhs) { return x = x * inv(rhs.x, M) % M, *this; }
    Mod pow(auto y) const { // O(log y) | 0^(-inf,0] -> 1
    Mod ans(1), base(*this);
    for (auto e = y < 0 ? ~y + u128(1) : +y; e; e >>= 1, base *= base) {
        e & 1 ? ans *= base : ans;
    }
    return y < 0 ? Mod(1) /= ans : ans;
    }
};
 
using mint = Mod<int, 998244353>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<vector<int>> new_adj(n);
    vector<int> stats(n+5,-1);
    vector<bool> vis(n,0);
    auto dfs=[&](int u,int x,auto &&dfs)->void
    {
        vis[u]=1;
        stats[u]=x;
        for(auto i:adjlist[u])
        {
            if(not vis[i] and a[i]==a[u])
            {
                dfs(i,x,dfs);
            }
        }
    };
    if(a[0]>a[n-1])
    {
        cout << "0\n";
        return;
    }
    int cc=0;
    for(int i=0;i<n;i++)
    {
        if(not vis[i] and a[i]>=a[0] and a[i]<=a[n-1])
        {
            dfs(i,cc,dfs);
            cc++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(auto j:adjlist[i])
        {
            if(stats[j]!=-1 and stats[i]!=-1 and stats[j]!=stats[i])
            {
                if(a[i]>=a[j])
                {
                    new_adj[stats[j]].push_back(stats[i]);
                }
                else
                {
                    new_adj[stats[i]].push_back(stats[j]);
                }
            }
        }
    }
    vector<int> dp(n,-1);
    dp[stats[n-1]]=1;
    auto run_dp=[&](int u,auto &&run_dp)->int
    {
        if(dp[u]!=-1)
        {
            return dp[u];
        }
        int ans=LLONG_MIN/20;
        for(auto i:new_adj[u])
        {
            ans=max(ans,run_dp(i,run_dp)+1);
        }
        return dp[u]=ans;
    };
    run_dp(stats[0],run_dp);
    cout << max(0LL,dp[stats[0]]) << '\n';
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