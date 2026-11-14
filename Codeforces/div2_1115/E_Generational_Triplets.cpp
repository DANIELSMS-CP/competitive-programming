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
 
using mint = ModInt<(int)(1e9+7)>;

mint dp[65][2][2][2];
bool vis[65][2][2][2];
int n;
mint solve_dp(int bit,int c_less,int a_less,int need)
{
    if(bit<0)
    {
        if(a_less and need==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(vis[bit][c_less][a_less][need]) 
    {
        return dp[bit][c_less][a_less][need];
    }
    mint ans=0;
    int n_bit=(n>>bit)&1;
    for(int a_bit=0;a_bit<=1;a_bit++)
    {
        for(int c_bit=0;c_bit<=1;c_bit++)
        {
            if(c_less and c_bit>n_bit)
            {
                continue;
            }
            if(not a_less and a_bit>c_bit)
            {
                continue;
            }
            if(need==1 and (a_bit&c_bit)==0)
            {
                continue;
            }
            if(need==0 and (a_bit&c_bit)==1)
            {
                continue;
            }
            int lower_c=(c_less&(c_bit==n_bit));
            int lower_a=(a_less|(a_bit<c_bit));
            int need_next=(a_bit^c_bit);
            ans+=solve_dp(bit-1,lower_c,lower_a,need_next);
        }
    }
    vis[bit][c_less][a_less][need]=1;
    return dp[bit][c_less][a_less][need]=ans;
}
void solve()
{
    cin >> n;
    memset(vis,false,sizeof(vis));
    cout << solve_dp(60,1,0,0) << '\n';
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
/*
a xor c = b
(a+c)/2 = b

a xor c = (a+c)/2
a+c - 2*(a xor c)==0
2(a and c) = a xor c
2 = shift right 1

10 = 1010
101

15 = 1111
111 

011
001

010=2
110=6
100=4
2 5 8
2 6 10

0010
0101
1000

0010
0110
1010

1 3 5
2 4 6
3 5 7
4 6 8
*/