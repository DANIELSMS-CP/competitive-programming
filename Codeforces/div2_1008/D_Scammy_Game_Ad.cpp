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

struct Int
{
    int x,x2;
    char c,c2;
};
void solve()
{
    int n;
    cin >> n;
    vector<Int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].c >> a[i].x >> a[i].c2 >> a[i].x2;
    }
    vector<vector<int>> track(n,vector<int>(2));
    int tracker=n;
    for(int i=n-1;i>=0;i--)
    {
        track[i][0]=tracker;
        if(a[i].c=='x' and a[i].c2=='+')
        {
            tracker=i;
        }
        if(a[i].c=='x' and a[i].c2=='x' and a[i].x>a[i].x2)
        {
            tracker=i;
        }
    }
    tracker=n;
    for(int i=n-1;i>=0;i--)
    {
        track[i][1]=tracker;
        if(a[i].c=='+' and a[i].c2=='x')
        {
            tracker=i;
        }
        if(a[i].c=='x' and a[i].c2=='x' and a[i].x2>a[i].x)
        {
            tracker=i;
        }
    }
    pair<int,int> ppl={1,1};
    for(int i=0;i<n;i++)
    {
        int moveable=0;
        if(a[i].c=='x')
        {
            moveable+=(a[i].x-1)*ppl.first;
        }
        else
        {
            moveable+=a[i].x;
        }
        if(a[i].c2=='x')
        {
            moveable+=(a[i].x2-1)*ppl.second;
        }
        else
        {
            moveable+=a[i].x2;
        }
        bool goLeft=(track[i][0]<track[i][1]);
        if(goLeft)
        {
            ppl.first+=moveable;
        }
        else
        {
            ppl.second+=moveable;
        }
    }
    cout << ppl.first+ppl.second << '\n';
}
signed main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
// 11 11
// 21 27
// 24 81