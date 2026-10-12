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

bool within_range(int l,int r ,int a)
{
    return (a>=l and a<=r);
}
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m),c(k);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }
    for(int i=0;i<k;i++)
    {
        cin >> c[i];
    }
    // sort(all(b));
    sort(all(c));
    int lf=0,ri=1,mx=0;
    vector<int> diff;
    for(int i=1;i<n;i++)
    {
        if(mx<a[i]-a[i-1])
        {
            lf=a[i-1],ri=a[i],mx=a[i]-a[i-1];
        }
        diff.push_back(a[i]-a[i-1]);
    }
    sort(all(diff));
    if(sz(diff)>1 and diff[sz(diff)-1]==diff[sz(diff)-2])
    {
        cout << mx << '\n';
        return;
    }
    int ans=mx;
    for(int i=0;i<m;i++)
    {
        int need=(lf+ri)/2-b[i];
        auto it=lower_bound(all(c),need);
        if(it!=c.end())
        {
            int x=b[i]+*it;
            if(within_range(lf,ri,x))
            {
                int ans2=max({x-lf,ri-x});
                if(sz(diff)>1)
                {
                    ans2=max(ans2,diff[sz(diff)-2]);
                }
                ans=min(ans,ans2);
            }
        }
        if(it!=c.begin())
        {
            it--;
            int x=b[i]+*it;
            if(within_range(lf,ri,x))
            {
                int ans2=max({x-lf,ri-x});
                if(sz(diff)>1)
                {
                    ans2=max(ans2,diff[sz(diff)-2]);
                }
                ans=min(ans,ans2);
            }
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