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

const int MAX_VAL = 600005;
struct node {
    int val;
    node *left, *right;

    node() : val(0), left(nullptr), right(nullptr) {}

    // Update value at position p
    void upd(int s, int e, int p, int v) {
        if (s == e) {
            val += v;
            return;
        }
        int m = s + (e - s) / 2;
        if (p <= m) {
            if (!left) left = new node();
            left->upd(s, m, p, v);
        } else {
            if (!right) right = new node();
            right->upd(m + 1, e, p, v);
        }
        
        // Sum of children
        int l_val = (left ? left->val : 0);
        int r_val = (right ? right->val : 0);
        val = l_val + r_val;
    }

    // Query range sum [l, r]
    int qry(int s, int e, int l, int r) {
        if (l > e || r < s) return 0;
        if (l <= s && e <= r) return val;
        
        int m = s + (e - s) / 2;
        int res = 0;
        if (left) res += left->qry(s, m, l, r);
        if (right) res += right->qry(m + 1, e, l, r);
        return res;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> a(3*n+10,0);
    node segtree;
    segtree.upd(0,MAX_VAL,0,n);
    vector<int> aa(n,0);
    int rem=0;
    while(q--)
    {
        int quer,x;
        cin >> quer >> x;
        if(quer==1)
        {
            x--;
            segtree.upd(0,MAX_VAL,aa[x],-1);
            aa[x]++;
            segtree.upd(0,MAX_VAL,aa[x],1);
            if(segtree.qry(0,MAX_VAL,rem+1,MAX_VAL)==n)
            {
                rem++;
            }
        }
        else
        {
            cout << segtree.qry(0,MAX_VAL,x+rem,MAX_VAL) << '\n';
        }
    }
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