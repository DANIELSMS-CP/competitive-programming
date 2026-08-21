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
    int val,mnv,mxv;
    node *left,*right;
    node(int ss,int ee,vector<int> &a)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        if(s==e)
        {
            val=0;
            mnv=a[e];
            mxv=a[e];
            return;
        }
        left=new node(s,m,a);
        right=new node(m+1,e,a);
        val=max({left->val,right->val,right->mxv-left->mnv}); // !!
        mnv=min(left->mnv,right->mnv);                        // !!
        mxv=max(left->mxv,right->mxv);                        // !!

    }
    void upd(int p,int v)
    {
        if(s==e)
        {
            val=0; // !!
            mnv=v;
            mxv=v;
            return;
        }
        int m=(s+e)/2;
        if(p<=m)
        {
            left->upd(p,v);
        }
        else
        {
            right->upd(p,v);
        }
        val=max({left->val,right->val,right->mxv-left->mnv}); // !!
        mnv=min(left->mnv,right->mnv);                        // !!
        mxv=max(left->mxv,right->mxv);                        // !!
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int> e(n,0);
    node s0(0,n-1,e),s1(0,n-1,e);
    for(int i=0;i<n;i++)
    {
        s0.upd(i,a[i]-i);
        s1.upd(i,-a[i]-i);
    }
    cout << max(s0.val,s1.val) << '\n';
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        x--;
        s0.upd(x,y-x);
        s1.upd(x,-y-x);
        cout << max(s0.val,s1.val) << '\n';
    }
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
max(a)+l-min(a)-r;

so find max a and find l
fix answer, let our current element be the max

can we bruteforce

we need to find the smaller number that is on the left of ai
and find the min

ai and i can be fixed, so just need to find min

if i go the left the prefix min would just get smaller

+l-min

range

longer range can get more max and less min
*/