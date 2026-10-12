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
// modint template: https://nyaannyaan.github.io/library/modint/modint.hpp.html~
template <int mod>
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+() const { return ModInt(*this); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }

  int get() const { return x; }

  static constexpr int get_mod() { return mod; }
};
 
using mint = ModInt<998244353>;

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
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    vector<int> mpa(n),mpb(n);
    int l=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mpa[i]=l;
        l++;
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        mpb[i]=l;
        l++;
    }
    vector<array<int,3>> vp;
    for(int i=0;i<n;i++)
    {  
        vp.push_back({((a[i]==b[i])?2:1),mpa[i],mpb[i]});
        if(i-1>=0)
        {
            vp.push_back({((a[i]==b[i-1])?2:1),mpa[i],mpb[i-1]});
        }
        if(i+1<n)
        {
            vp.push_back({((a[i]==b[i+1])?2:1),mpa[i],mpb[i+1]});
        }
    }
    sort(all(vp));
    reverse(all(vp));
    int ans=0;
    DSU dsu(4*n+5);
    for(int i=0;i<sz(vp);i++)
    {
        if(dsu.find_par(vp[i][1])!=dsu.find_par(vp[i][2]))
        {
            ans+=vp[i][0];
            dsu.merge(vp[i][1],vp[i][2]);
        }
    }
    cout << ans << '\n';
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