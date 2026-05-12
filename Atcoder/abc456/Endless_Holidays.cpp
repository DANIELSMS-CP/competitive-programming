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

struct info
{
    int u,w;
    bool operator<(const info &other) const {
    if (u != other.u) return u < other.u;
    return w < other.w;
    }
    bool operator==(const info &other) const { return u==other.u && w==other.w; }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> u(m+1),v(m+1);
    map<info,vector<info>> adjlist;
    for(int i=0;i<m;i++)
    {
        cin >> u[i] >> v[i];
    }
    int days;
    cin >> days;
    vector<string> d(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> d[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=days;j++)
        {   
            if(d[u[i]][j%days]=='o' and d[v[i]][j-1]=='o')
            {
                adjlist[{v[i],j-1}].push_back({u[i],j%days});
            }
            if(d[u[i]][j-1]=='o' and d[v[i]][j%days]=='o')
            {
                adjlist[{u[i],j-1}].push_back({v[i],j%days});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=days;j++)
        {   
            if(d[i][j-1]=='o' and d[i][j%days]=='o')
            {
                adjlist[{i,j-1}].push_back({i,j%days});
            }
        }
    }
    bool found=0;
    map<info,int> vis;
    auto dfs=[&](info u,auto &&dfs)->void
    {
        vis[u]=1;
        for(auto i:adjlist[u])
        {
            if(vis[i]==2)
            {
                continue;
            }
            if(vis[i]==1)
            {
                cout << "Yes\n";
                found=1;
                return;
            }
            else if(vis[i]==0)
            {
                dfs(i,dfs);
                if(found)
                {
                    return;
                }
            }
        }
        vis[u]=2;
    };
    for(int i=1;i<=n;i++)
    {
        if(d[i][0]=='o' and not vis[{i,0}])
        {
            dfs({i,0},dfs);
            if(found)
            {
                return;
            }
        }
    }
    cout << "No\n";
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