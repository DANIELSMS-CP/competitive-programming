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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(a[0]);
    int cnt=1,ans=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=v.back())
        {
            ans++;
            cnt=1;
            v.push_back(a[i]);
        }
        else
        {
            if(cnt<2)
            {
                v.push_back(a[i]);
            }
            cnt++;
        }
    }
    if(sz(v)==1)
    {
        cout << "1\n";
        return;
    }
    if(sz(v)==2)
    {
        cout << 1+(v[0]!=v[1]) << '\n';
        return;
    }
    v=a;
    for(int i=1;i<sz(v);i++)
    {
        if(v[i]==v[i-1])
        {
            if(i-2>=0 and v[i-1]!=v[i-2])
            {
                if(i-3>=0 and v[i-2]==v[i-3])
                {
                    cout << ans+2 << '\n';
                    return;
                }
            }
            if(i+1<n and v[i]!=v[i+1])
            {
                if(i+2<n and v[i+2]==v[i+1])
                {
                    cout << ans+2 << '\n';
                    return;
                }
            }
        }
    }
    for(int i=1;i<sz(v);i++)
    {
        if(v[i]==v[i-1])
        {
            if(i+1<n and v[i+1]!=v[i])
            {
                if(i+2>=n or (i+2<n and v[i+2]!=v[i]))
                {
                    cout << ans+1 << '\n';
                    return;
                }
            }
            if(i-2>=0 and v[i-2]!=v[i])
            {
                if(i-3<0 or (i-3>=0 and v[i-3]!=v[i]))
                {
                    cout << ans+1 << '\n';
                    return;
                }
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
        // debug(t)
        solve();
    }

    return 0;
}


// // 1 1 2 3
// 1 2 1 3
// // 3 2 1 1
// 3 1 2 1
// // 3 1 1 2
// 3 1 2 1

// 3 3 2 2 2 = 2
// 3 2 3 2 2 = 4

// 3 2 2 3 2 = 3 

// 2 2 2 3 4 = 2 2 3 2 4
// 2 3 2 2 4 = 2 3

// 1 2 1 1 3 4

