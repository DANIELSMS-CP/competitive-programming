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

string a,b;
int dp[25][2][2][2];
string print_later[25][2][2][2];
int solve_dp(int pos,int upper,int lower,int leading)
{
    if(pos>=sz(a))
    {
        return 1;
    }
    if(dp[pos][upper][lower][leading]!=-1)
    {
        return dp[pos][upper][lower][leading];
    }
    int ans=0;
    int mn_digit=(lower?(ll)(b[pos]-'0'):0LL);
    int mx_digit=(upper?(ll)(a[pos]-'0'):9LL);
    for(int i=mn_digit;i<=mx_digit;i++)
    {
        int new_upper=(upper and (i==a[pos]-'0'));
        int new_lower=(lower and (i==b[pos]-'0'));
        int new_leading=(leading and (i==0));
        if(new_leading)
        {
            if(ans<=solve_dp(pos+1,new_upper,new_lower,new_leading))
            {
                ans=solve_dp(pos+1,new_upper,new_lower,new_leading);
                print_later[pos][upper][lower][leading]=print_later[pos+1][new_upper][new_lower][new_leading];
            }
        }
        else
        {
            if(ans<=solve_dp(pos+1,new_upper,new_lower,new_leading)*i)
            {
                ans=solve_dp(pos+1,new_upper,new_lower,new_leading)*i;
                print_later[pos][upper][lower][leading]=to_string(i)+print_later[pos+1][new_upper][new_lower][new_leading];
            }
        }
    }
    return dp[pos][upper][lower][leading]=ans;
}
void solve()
{
    cin >> b >> a;
    memset(dp,-1,sizeof(dp));
    while(sz(b)<sz(a))
    {
        b='0'+b;
    }
    solve_dp(0,1,1,1);
    cout << print_later[0][1][1][1] << '\n';
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