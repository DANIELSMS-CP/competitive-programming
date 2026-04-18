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

struct DSU
{
    vector<int> par,sz;
    DSU(int n)
    {
        par.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int find_par(int u)
    {
        return par[u]=(u==par[u]?u:find_par(par[u]));
    }
    bool merge(int a,int b)
    {
        int x=find_par(a);
        int y=find_par(b);
        if(x==y)
        {
            return false;
        }
        if(sz[x]>sz[y])
        {
            swap(x,y);
        }
        par[x]=y;
        sz[y]+=sz[x];
        return true;
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    DSU dsu(n+1);
    vector<vector<int>> szcolor(n+1,vector<int>(2,0));
    vector<int> color(n+1,0);
    for(int i=1;i<=n;i++)
    {
        szcolor[i][0]=1;
    }
    vector<set<int>> st(n+1);
    for(int i=1;i<=n;i++)
    {
        st[i].insert(i);
    }
    bool disabled=0;
    int total_ans=0;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        int fu=dsu.find_par(u);
        int fv=dsu.find_par(v);
        if(disabled)
        {
            cout << "-1\n";
            continue;
        }
        if(fu!=fv)
        {
            total_ans-=min(szcolor[fu][0],szcolor[fu][1]);
            total_ans-=min(szcolor[fv][0],szcolor[fv][1]);
            dsu.merge(u,v);
            int root=dsu.find_par(u);
            int root2=((root==fu)?fv:fu);
            if(color[u]==color[v])
            {
                for(auto i:st[root2])
                {
                    color[i]^=1;
                }
                swap(szcolor[root2][0], szcolor[root2][1]);
            }
            for(auto i:st[root2])
            {
                st[root].insert(i);
            }
            st[root2].clear();
            szcolor[root][0]+=szcolor[root2][0];
            szcolor[root][1]+=szcolor[root2][1];
            szcolor[root2][0]=0;
            szcolor[root2][1]=0;
            total_ans+=min(szcolor[root][0],szcolor[root][1]);
            cout << total_ans << '\n';
        }
        else
        {
            if(color[u]==color[v])
            {
                disabled=1;
                cout << "-1\n";
            }
            else
            {
                cout << total_ans << '\n';
            }
        }
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