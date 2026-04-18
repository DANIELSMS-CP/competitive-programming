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

using mint = Mod<int, (int)(1e9+7)>;
struct node {
    int s, e;
    mint val; 
    node *left, *right;

    node(int ss, int ee) : s(ss), e(ee), val(0), left(nullptr), right(nullptr) {}

    void upd(int p, int v) {
        if (s == e) {
            val = v;
            return;
        }

        int m = s + (e - s) / 2; 
        if (p <= m) {
            if (!left) left = new node(s, m);
            left->upd(p, v);
        } else {
            if (!right) right = new node(m + 1, e); 
            right->upd(p, v);
        }

        val = (left ? left->val : mint(0)) + (right ? right->val : mint(0));
    }

    long long qry(int l, int r) {
        if (l > e || r < s) return 0;

        if (l <= s && e <= r) return val;

        long long res = 0;
        if (left) res += left->qry(l, r);
        if (right) res += right->qry(l, r);
        return res;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    mint dp[n+1],dp2[n+1];
    fill(dp,dp+n+1,0);
    fill(dp2,dp2+n+1,0);
    node segtree(0,mx+1),segtree2(0,mx+1);
    set<int> odd,even;
    segtree.upd(0,1);
    segtree2.upd(0,1);
    odd.insert(-1);
    even.insert(-1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2)
        {
            auto lb=even.lower_bound(a[i]);
            lb--;
            int lb2=*lb;
            dp[i]+=segtree2.qry(0,lb2+1);
            odd.insert(a[i]);
            segtree.upd(a[i],dp[i]);
        }
        else
        {
            auto lb=odd.lower_bound(a[i]);
            lb--;
            int lb2=*lb;
            dp2[i]+=segtree.qry(0,lb2+1);
            even.insert(a[i]);
            segtree2.upd(a[i],dp2[i]);
        }
    }
    mint sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=dp[i]+dp2[i];
    }
    cout << sum << '\n';
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