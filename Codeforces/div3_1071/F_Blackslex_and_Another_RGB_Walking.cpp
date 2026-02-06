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

vector<vector<int>> adjlist(200005);
vector<int> vc(200005);
void solvef()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<=n;i++)
    {
        adjlist[i].clear();
        vc[i]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    vector<int> dist(n+1,LLONG_MAX/20);
    dist[0]=0;
    string rgb="rgb";
    vc[0]=0;
    while(not q.empty())
    {
        int tt=q.front();
        q.pop();
        for(auto i:adjlist[tt])
        {
            if(dist[i]==LLONG_MAX/20)
            {
                vc[i]=(vc[tt]+1)%3;
                q.push(i);
                dist[i]=dist[tt]+1;
            }
        }
    }
    string ans;
    for(int i=0;i<n;i++)
    {
        ans+=rgb[vc[i]];
    }
    cout << ans << '\n';
}
void solves()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cr=count(all(s),'r');
        int cg=count(all(s),'g');
        int cb=count(all(s),'b');
        if((cr==0 and cg==0) or (cr==0 and cb==0) or (cg==0 and cb==0))
        {
            cout << 1 << '\n';
            continue;
        }
        if(cg==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='r')
                {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
        else if(cb==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='g')
                {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
        else if(cr==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='b')
                {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
    }
}
signed main()
{
    fastio();
    string s;
    cin >> s;
    int t=1;
    cin >> t;
    while(t--)
    {
        if(s=="first")
        {
            solvef();
        }
        else
        {
            solves();
        }
    }

    return 0;
}