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

vector<int> solve2(int n,vector<int> &a,map<int,int> &cnt)
{
    int mex=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<mex)
        {
            continue;
        }
        if(a[i]>mex)
        {
            break;
        }
        mex++;
    }
    vector<int> a2(n);
    for(int i=0;i<n;i++)
    {
        if(cnt[a[i]]-1==0 and a[i]<=mex)
        {
            a2[i]=a[i];
        }
        else
        {
            a2[i]=mex;
        }
    }
    return a2;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(all(a));
    vector<int> a2=solve2(n,a,cnt);
    map<int,int> cnt2;
    for(int i=0;i<n;i++)
    {
        cnt2[a2[i]]++;
    }
    vector<int> a3=solve2(n,a2,cnt2);
    map<int,int> cnt3;
    for(int i=0;i<n;i++)
    {
        cnt3[a3[i]]++;
    }
    vector<int> a4=solve2(n,a3,cnt3);
    map<int,int> cnt4;
    for(int i=0;i<n;i++)
    {
        cnt4[a4[i]]++;
    }
    vector<int> ans;
    if(m==1)
    {
        ans=a2;
    }
    else if(m==2)
    {
        ans=a3;
    }
    else if(m==3)
    {
        ans=a4;
    }
    else
    {
        if(m%2==0)
        {
            ans=a3;
        }
        else
        {
            ans=a4;
        }
    }
    int sum=accumulate(all(ans),0LL);
    // for(auto i:a3)
    // {
    //     cerr << i << ' ';
    // }
    cout << sum << '\n';
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


// 6 6 2 4 3 0 1 8
// 5 5 2 4 3 0 1 5
// 6 6 2 4 3 0 1 6
// 5 5 2 3 4 0 1 5
// 6 6 2 3 4 0 1 6
// 5 5 2 3 4 0 1 5
// 6 6 2 3 4 0 1 6
// 5 5 2 3 4 0 1 5

// 0 0 1 1 2 2
// 3 3 3 3 3 3
// 0 0 0 0 0 0
// 1 1 1 1 1 1
