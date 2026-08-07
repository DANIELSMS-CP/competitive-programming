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
    string s,u;
    cin >> s >> u;
    map<char,int> mp;
    mp['A']=0;
    mp['C']=1;
    mp['T']=2;
    vector<vector<int>> pref(3,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            pref[j][i]=pref[j][i-1];
            if(mp[s[i-1]]==j)
            {
                pref[j][i]++;
            }
        }
    }
    vector<vector<int>> pref2(3,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            pref2[j][i]=pref2[j][i-1];
            if(mp[u[i-1]]==j)
            {
                pref2[j][i]++;
            }
        }
    }
    map<pair<char,char>,int> mp2;
    int id=0;
    for(char c:{'A','C','T'})
    {
        for(char c2:{'A','C','T'})
        {
            if(c!=c2)
            {
                mp2[{c,c2}]=id;
                id++;
            }
        }
    }
    vector<vector<int>> pref3(20,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(auto [key,val]:mp2)
        {
            pref3[val][i]=pref3[val][i-1];
        }
        if(s[i-1]!=u[i-1])
        {
            pref3[mp2[{s[i-1],u[i-1]}]][i]++;
        }
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l++,r++;
        bool can=1;
        for(int i=0;i<3;i++)
        {
            if(pref[i][r]-pref[i][l-1]!=pref2[i][r]-pref2[i][l-1])
            {
                can=0;
                break;
            }
        }
        if(can)
        {
            int rem=0;
            int ans=0;
            map<pair<char,char>,bool> vis;
            for(char c:{'A','C','T'})
            {
                for(char c2:{'A','C','T'})
                {
                    if(c!=c2 and not vis[{c,c2}] and not vis[{c2,c}])
                    {
                        int tot=pref3[mp2[{c,c2}]][r]-pref3[mp2[{c,c2}]][l-1];
                        int tot2=pref3[mp2[{c2,c}]][r]-pref3[mp2[{c2,c}]][l-1];
                        ans+=min(tot,tot2);
                        rem=max(tot,tot2)-min(tot,tot2);
                        vis[{c,c2}]=1;
                        vis[{c2,c}]=1;
                    }
                }
            }
            ans+=rem*2;
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
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