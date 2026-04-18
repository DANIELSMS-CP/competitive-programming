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
    string a,b;
    cin >> a >> b;
    vector<int> lenz(120,0);
    vector<vector<int>> freq(120,vector<int>(27,0));
    lenz[1]=sz(a);
    lenz[2]=sz(b);
    for(auto i:a)
    {
        freq[1][i-'a']++;
    }
    for(auto i:b)
    {
        freq[2][i-'a']++;
    }
    for(int i=3;i<=100;i++)
    {
        lenz[i]=min((int)(LLONG_MAX/5),(lenz[i-1]+lenz[i-2]));
        for(int j=0;j<26;j++)
        {
            freq[i][j]=freq[i-1][j]+freq[i-2][j];
        }
    }
    auto dfs=[&](int idx,int k,char c,auto &&dfs)->int
    {
        if(k==0)
        {
            return 0;
        }
        if(idx==1)
        {
            int res=0;
            for(int i=0;i<k;i++)
            {
                if(a[i]==c)
                {
                    res++;
                }
            }
            return res;
        }
        if(idx==2)
        {
            int res=0;
            for(int i=0;i<k;i++)
            {
                if(b[i]==c)
                {
                    res++;
                }
            }
            return res;
        }
        if(k==lenz[idx])
        {
            return freq[idx][c-'a'];
        }
        if(k<=lenz[idx-1])
        {
            return dfs(idx-1,k,c,dfs);
        }
        else
        {
            return freq[idx-1][c-'a']+dfs(idx-2,k-lenz[idx-1],c,dfs);
        }
    };
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        char c;
        cin >> l >> r >> c;
        cout << dfs(100,r,c,dfs)-dfs(100,l-1,c,dfs) << '\n';
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