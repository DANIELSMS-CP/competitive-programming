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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<char>> tmp=a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
            {
                tmp[i][j]='.';
                for(int k=-1;k<=1;k++)
                {
                    for(int l=-1;l<=1;l++)
                    {
                        if(k==0 and l==0)
                        {
                            continue;
                        }
                        if(i+k>=0 and i+k<n and j+l>=0 and j+l<m and a[i+k][j+l]=='.')
                        {
                            tmp[i+k][j+l]='#';
                        }
                    }
                }
            }
        }
    }
    a=tmp;
    vector<vector<int>> md(n,vector<int>(m,LLONG_MAX/20)),vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
            {
                q.push({i,j});
                vis[i][j]=1;
                md[i][j]=0;
            }
        }
    }
    if(q.empty())
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << '.';
            }
            cout << '\n';
        }
        return;
    }
    while(not q.empty())
    {
        auto t=q.front();
        q.pop();
        int i=t.first;
        int j=t.second;
        for(int k=-1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                if(k==0 and l==0)
                {
                    continue;
                }
                if(i+k>=0 and i+k<n and j+l>=0 and j+l<m and not vis[i+k][j+l])
                {
                    md[i+k][j+l]=md[i][j]+1;
                    vis[i+k][j+l]=1;
                    q.push({i+k,j+l});
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(md[i][j]%2)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << '\n';
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