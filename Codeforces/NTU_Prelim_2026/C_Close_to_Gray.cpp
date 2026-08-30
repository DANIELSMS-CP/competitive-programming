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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjlist(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u); 
    }
    vector<int> black(n+1,0),white(n+1,0);
    int cc=1;
	vector<int> vis(n+1,0);
	auto dfs=[&](int u,auto &&dfs)->void
	{
		vis[u]=1;
		black[u]=cc;
		for(auto i:adjlist[u])
		{
			if(not vis[i])
			{
				dfs(i,dfs);
			}
		}
	};
    for(int i=1;i<=n;i++)
    {
        if(not vis[i])
		{
			dfs(i,dfs);
			cc++;
		}
    }
	int cc2=1;
	vector<int> vis2(n+1,0);
	set<int> unvis;
	for(int i=1;i<=n;i++)
	{
		unvis.insert(i);
	}
	vector<int> mark(n+1,0);
	int timer=0;
	while(not unvis.empty())
	{
		int start=*unvis.begin();
		unvis.erase(start);
		queue<int> q;
		q.push(start);
		white[start]=cc2;
		while(not q.empty())
		{
			int u=q.front();
			q.pop();
			timer++;
			for(auto i:adjlist[u])
			{
				mark[i]=timer;
			}
			vector<int> nxt;
			for(auto i:unvis)
			{
				if(mark[i]!=timer)
				{
					nxt.push_back(i);
				}
			}
			for(auto i:nxt)
			{
				white[i]=cc2;
				unvis.erase(i);
				q.push(i);
			}
		}
		cc2++;
	}
	map<pair<int,int>,int> cc_sz;
	for(int i=1;i<=n;i++)
	{
		cc_sz[{black[i],white[i]}]++;
	}
	int ans=0;
	for(auto [key,val]:cc_sz)
	{
		ans+=val*(val-1)/2;
	}
	cout << ans << '\n';
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
// graph like ribbon cant AC