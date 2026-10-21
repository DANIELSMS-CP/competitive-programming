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

bool check_valid(vector<int> &a)
{
    int n=sz(a);
    map<int,bool> seen;
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j<n and a[i]==a[j])
        {
            j++;
        }
        if(seen[a[i]])
        {
            return false;
        }
        seen[a[i]]=true;
        i=j-1;
    }
    return true;
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
    map<int,vector<int>> pos;
    for(int i=0;i<n;i++)
    {
        pos[a[i]].push_back(i);
    }
    int fix=0;
    for(auto [key,val]:pos)
    {
        if(*val.rbegin()-*val.begin()+1!=sz(val))
        {
            fix=key;
        }
    }
    if(fix==0)
    {
        cout << "YES\n";
        return;
    }
    int gap=0;
    for(int i=2;i<sz(pos[fix]);i++)
    {
        if(pos[fix][i]-1!=pos[fix][i-1])
        {
            gap=pos[fix][i]-1;
            break;
        }
    }
    int gap2=0;
    for(int i=sz(pos[fix])-3;i>=0;i--)
    {
        if(pos[fix][i]+1!=pos[fix][i+1])
        {
            gap2=pos[fix][i]+1;
            break;
        }
    }
    bool valid=0;
    swap(a[pos[fix][0]],a[pos[fix][1]-1]);
    valid=(valid|check_valid(a));
    swap(a[pos[fix][0]],a[pos[fix][1]-1]);
    if(pos[fix].back()+1<n)
    {
        swap(a[pos[fix][0]],a[pos[fix].back()+1]);
        valid=(valid|check_valid(a));
        swap(a[pos[fix][0]],a[pos[fix].back()+1]);
    }
    swap(a[pos[fix][0]],a[gap]);
    valid=(valid|check_valid(a));
    swap(a[pos[fix][0]],a[gap]);
    
    swap(a[pos[fix].back()],a[pos[fix][sz(pos[fix])-2]+1]);
    valid=(valid|check_valid(a));
    swap(a[pos[fix].back()],a[pos[fix][sz(pos[fix])-2]+1]);
    if(pos[fix][0]-1>=0)
    {
        swap(a[pos[fix].back()],a[pos[fix][0]-1]);
        valid=(valid|check_valid(a));
        swap(a[pos[fix].back()],a[pos[fix][0]-1]);
    }
    swap(a[pos[fix].back()],a[gap2]);
    valid=(valid|check_valid(a));
    swap(a[pos[fix].back()],a[gap2]);

    if(valid)
    {
        cout << "YES\n";
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