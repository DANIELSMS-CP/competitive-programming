// 道草を楽しめ 大いにな。ほしいものより大切なものが きっとそっちに ころがってる
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

//Template
template<class T> using V=vector<T>;
template<class T,int S> using A=array<T,S>;
template<class K,class V> using H=unordered_map<K,V>;
template<class T,class U=less<T>> using oset=tree<T,null_type,U,rb_tree_tag,tree_order_statistics_node_update>;

template <auto M, class T = decay_t<decltype(M)>>
struct Mod {
  using V = conditional_t<(M < ~u32(0) / 2), u64, u128>;
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
using mint = Mod<998244353>;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<vector<int>> adjlist(n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> dep(n,0),par(n,-1);
    auto dfs=[&](int u,int v,auto &&dfs)->void
    {
        for(auto i:adjlist[u])
        {
            if(i!=v)
            {
                dep[i]=dep[u]+1;
                par[i]=u;
                dfs(i,u,dfs);
            }
        }
    };
    dfs(0,0,dfs);
    vector<int> ch_cnt(n,0);
    for(int i=1;i<n;i++)
    {
        ch_cnt[par[i]]+=a[i];
    }
    int leaves=0;
    set<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        {
            leaves+=(ch_cnt[i]==0);
            st.insert({dep[i],i});
        }
    }
    while(q--)
    {
        int u;
        cin >> u;
        u--;
        if(st.count({dep[u],u}))
        {
            st.erase({dep[u],u});
        }
        else
        {
            st.insert({dep[u],u});
        }
        leaves-=(a[u] and ch_cnt[u]==0);
        if(u)
        {
            leaves-=(a[par[u]] and ch_cnt[par[u]]==0);
            ch_cnt[par[u]]-=a[u];
        }
        a[u]^=1;
        leaves+=(a[u] and ch_cnt[u]==0);
        if(u) 
        {
            ch_cnt[par[u]]+=a[u];
            leaves+=(a[par[u]] and ch_cnt[par[u]]==0);
        }
        int h=(*st.begin()).second;
        cout << (leaves==1 or (leaves==2 and a[h] and ch_cnt[h]==2)?"Yes\n":"No\n");
    }
}

signed main() {
    fastio();
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}