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

struct info
{
    int a,b,c;
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    pair<int,int> start,end;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='T')
            {
                end={i,j};
            }
            if(a[i][j]=='S')
            {
                start={i,j};
            }
        }
    }    
    int qq;
    cin >> qq;
    vector<info> med(qq);
    int check_start=0;
    vector<vector<int>> mp(n,vector<int>(m,-1));
    for(int i=0;i<qq;i++)
    {
        cin >> med[i].a >> med[i].b >> med[i].c;
        med[i].a--,med[i].b--;
        if(a[med[i].a][med[i].b]=='T')
        {
            continue;
        }
        if(a[med[i].a][med[i].b]=='S')
        {
            check_start=i;
        }
        a[med[i].a][med[i].b]='M';
        mp[med[i].a][med[i].b]=i;
    }
    if(a[start.first][start.second]=='S')
    {
        cout << "No\n";
        return;
    }
    vector<vector<int>> adjlist(qq+1);
    for(int idk=0;idk<qq;idk++)
    {
        if(mp[med[idk].a][med[idk].b]==-1)
        {
            continue;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,LLONG_MAX/20));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        dist[med[idk].a][med[idk].b]=0;
        vis[med[idk].a][med[idk].b]=1;
        q.push({med[idk].a,med[idk].b});
        while(not q.empty())
        { 
            auto topz=q.front();
            q.pop();
            int x=topz.first,y=topz.second;
            for(int i=0;i<4;i++)
            {
                if(dx[i]+x>=0 and dx[i]+x<n and dy[i]+y>=0 and dy[i]+y<m and (not vis[dx[i]+x][dy[i]+y]) and dist[x][y]+1<=med[idk].c and a[dx[i]+x][dy[i]+y]!='#')
                {
                    vis[dx[i]+x][dy[i]+y]=1;
                    dist[dx[i]+x][dy[i]+y]=min(dist[dx[i]+x][dy[i]+y],dist[x][y]+1);
                    if(a[dx[i]+x][dy[i]+y]=='T')
                    {
                        adjlist[idk].push_back(qq);
                    }
                    else if(mp[dx[i]+x][dy[i]+y]!=-1)
                    {
                        adjlist[idk].push_back(mp[dx[i]+x][dy[i]+y]);
                    }
                    q.push({dx[i]+x,dy[i]+y});
                }
            }   
        }
    }  
    // for(int i=0;i<=qq;i++)
    // {
    //     cerr << i << ": ";
    //     for(auto j:adjlist[i])
    //     {
    //         cerr << j << ' ';
    //     }
    //     cerr << '\n';
    // }
    // debug(check_start)
    vector<int> vismeds(qq+1,0);
    vismeds[check_start]=1;
    auto dfs=[&](auto &dfs,int u)->bool
    {
        if(u==qq)
        {
            return true;
        }
        for(auto i:adjlist[u])
        {
            if(not vismeds[i])
            {
                vismeds[i]=1;
                if(dfs(dfs,i))
                {
                    return true;
                }
            }
        }
        return false;
    };
    // debug(a[start.first][start.second])
    cout << (dfs(dfs,check_start)?"Yes\n":"No\n");
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