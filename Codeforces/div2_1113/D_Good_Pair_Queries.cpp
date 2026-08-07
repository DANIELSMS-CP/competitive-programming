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
    int n,q;
    cin >> n >> q;
    string a,b;
    cin >> a >> b;
    vector<vector<int>> prefa(2,vector<int>(n+1,0));
    vector<vector<int>> prefb(2,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(char c:{'0','1'})
        {
            prefa[c-'0'][i+1]=prefa[c-'0'][i];
            prefb[c-'0'][i+1]=prefb[c-'0'][i];
            if(a[i]==c)
            {
                prefa[c-'0'][i+1]++;
            }
            if(b[i]==c)
            {
                prefb[c-'0'][i+1]++;
            }
        }
    }
    vector<int> pref0(n+1,0);
    vector<int> pref1(n+1,0);
    vector<int> pref2(n+1,0);
    vector<int> pref3(n+1,0);
    for(int i=0;i<n;i++)
    {
        pref0[i+1]=pref0[i];
        pref1[i+1]=pref1[i];
        pref2[i+1]=pref2[i];
        pref3[i+1]=pref3[i];
        if(a[i]==b[i])
        {
            if(a[i]=='0')
            {
                pref0[i+1]++;
            }
            else
            {
                pref1[i+1]++;
            }
        }
        else
        {
            if(a[i]=='0' and b[i]=='1')
            {
                pref2[i+1]++;
            }
            else
            {
                pref3[i+1]++;
            }
        }
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int a0=prefa[0][r]-prefa[0][l-1];
        int b0=prefb[0][r]-prefb[0][l-1];
        int a1=prefa[1][r]-prefa[1][l-1];
        int b1=prefb[1][r]-prefb[1][l-1];
        if(a0>=a1 and b0>=b1)
        {
            cout << "YES\n";
            continue;
        }
        if(a1>=a0 and b1>=b0)
        {
            cout << "YES\n";
            continue;
        }
        int s0=pref0[r]-pref0[l-1];
        int s1=pref1[r]-pref1[l-1];
        int s2=pref2[r]-pref2[l-1]; // 01
        int s3=pref3[r]-pref3[l-1]; // 10
        if(abs(s2-s3)<=s0+s1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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
can always remove 00 or 11 first
can kill diff one by one
try to find mode for 2 substrings
if diff then kill by using the same


make 01 10 balanced

0100
0111
*/