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

int get_mex(set<int> st)
{
    int num=0;
    while(not st.empty() and *st.begin()==num)
    {
        st.erase(*st.begin());
        num++;
    }
    return num;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(all(a));
    set<int> sa,sb,sc;
    map<int,int> va,vb;
    vector<char> ans(n);
    for(int i=0;i<n;i++)
    {
        if(not va[a[i].first] and a[i].first==0)
        {
            va[a[i].first]=1;
            sa.insert(a[i].first);
            ans[a[i].second]='A';
        }
        else if(a[i].first==0)
        {
            vb[a[i].first]=1;
            sb.insert(a[i].first);
            ans[a[i].second]='B';
        }
        else
        {
            sc.insert(a[i].first);
            ans[a[i].second]='C';
        }
    }
    int ga=get_mex(sa);
    int gb=get_mex(sb);
    int gc=get_mex(sc);
    // debug(ga)
    // debug(gb)
    // debug(gc)
    if(ga+gb+gc>=2*max({ga,gb,gc}))
    {
        cout << "YES\n";
        for(auto i:ans)
        {
            cout << i;
        }
        cout << '\n';
    }
    else
    {
        cout << "NO\n";
    }
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
// 0 0 1 1 1 2
// a b a b c c