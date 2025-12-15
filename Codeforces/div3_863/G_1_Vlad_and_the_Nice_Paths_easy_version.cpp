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
 
using mint = Mod<int, (int)1e9+7>;

vector<mint> fact(1005);
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(k==1)
    {
        cout << "1\n";
        return;
    }
    vector<vector<mint>> dp(n+1,vector<mint>(n/k+1,mint(0)));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n/k;j++)
        {
            if(j>0)
            {
                int sz=1;
                for(int s=i-1;s>=1;s--)
                {
                    if(a[i]==a[s])
                    {
                        sz++;
                        if(sz>=k)
                        {
                            dp[i][j]+=dp[s-1][j-1]*(fact[sz-2]/fact[k-2]/fact[sz-k]);
                        }
                    }
                }
            }
            dp[i][j]+=dp[i-1][j];
        }
    }
    for(int i=n/k;i>=0;i--)
    {
        if(dp[n][i]>0)
        {
            cout << dp[n][i] << '\n';
            return;
        }
    }
}
signed main()
{
    fastio();
    fact[0]=1;
    fact[1]=1;
    for(int i=1;i<=1000;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
