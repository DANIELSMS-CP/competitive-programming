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

struct node
{
    int s,e,m;
    int val,lazy;
    node *left=nullptr,*right=nullptr;
    node(int ss,int ee)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        val=0;
        lazy=0;
    }
    void create()
    {
        if(s==e or left!=nullptr)
        {
            return;
        }
        left=new node(s,m);
        right=new node(m+1,e);
    }
    void upd(int l,int r,int v)
    {
        create();
        prop();
        if(l>e or r<s)
        {
            return;
        }
        if(l<=s and e<=r)
        {
            lazy+=v;
            return;
        }
        left->upd(l,r,v);
        right->upd(l,r,v);
        left->prop();
        right->prop();
        val=left->val+right->val;
    }
    int qry(int l,int r)
    {
        create();
        prop();
        if(l>e or r<s)
        {
            return 0;
        }
        if(l<=s and e<=r)
        {
            return val;
        }
        return left->qry(l,r)+right->qry(l,r);
    }
    void prop()
    {
        if(s!=e)
        {
            left->lazy+=lazy;
            right->lazy+=lazy;
        }
        val+=(e-s+1)*lazy;
        lazy=0;
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    node Segtree(0,n+10);
    for(int i=0;i<m;i++)
    {
        int q;
        cin >> q;
        if(q==1)
        {
            int l,r,k;
            cin >> l >> r >> k;
            Segtree.upd(l,r,k);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << Segtree.qry(l,r) << '\n';
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