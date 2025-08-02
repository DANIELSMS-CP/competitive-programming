//and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
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
const int MOD=998244353;
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

struct st{
    int l,r;
    mint prob;
};
void solve()
{
    int n,m;
    cin >> m >> n;
    vector<st> a(m+1);
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].l >> a[i].r;
        int x,y;
        cin >> x >> y;
        a[i].prob=x;
        a[i].prob/=y;
    }
    vector<vector<st>> L(n+1),R(n+1);
    for(int i=1;i<=m;i++)
    {
        L[a[i].l].push_back(a[i]);
        R[a[i].r].push_back(a[i]);
    }
    vector<mint> dp(n+1,mint(0));
    dp[0]=mint(1);
    vector<mint> notexist(n+1,mint(1));
    for(int i=1;i<=n;i++)
    {
        for(auto stt:L[i])
        {
            notexist[i]*=(mint(1)-stt.prob);
        }
    }
    vector<mint> pprod(n+1,mint(1));
    pprod[0]=1;
    for(int i=1;i<=n;i++)
    {
        pprod[i]*=notexist[i]*pprod[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(auto stt:R[i])
        {
            mint ne=pprod[stt.r]/pprod[stt.l-1];
            ne/=(mint(1)-stt.prob);
            dp[i]+=(stt.prob*dp[stt.l-1]*ne);
        }
    }
    cout << dp[n] << '\n';
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