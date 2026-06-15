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
    int s,t,l,k;
    cin >> s >> t >> l >> k;
    vector<vector<pair<int,int>>> adjlist(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int start=s;
    vector<int> dists(n+1,(int)(1e18));
    dists[start]=0;
    pq.push({0,start});
    while(not pq.empty())
    {
        auto topz=pq.top();
        pq.pop();
        int node=topz.second,weight=topz.first;
        if(dists[node]<weight)
        {
            continue;
        }
        for(auto i:adjlist[node])
        {
            int v = i.first;      // neighbor node
            int w = i.second;     // edge weight
            int new_dist=dists[node]+w;
            if(new_dist<dists[v])
            {
                dists[v]=new_dist;
                pq.push({dists[v],v});
            } 
        }
    }
    start=t;
    vector<int> distt(n+1,(int)(1e18));
    distt[start]=0;
    pq.push({0,start});
    while(not pq.empty())
    {
        auto topz=pq.top();
        pq.pop();
        int node=topz.second,weight=topz.first;
        if(distt[node]<weight)
        {
            continue;
        }
        for(auto i:adjlist[node])
        {
            int v = i.first;      // neighbor node
            int w = i.second;     // edge weight
            int new_dist=distt[node]+w;
            if(new_dist<distt[v])
            {
                distt[v]=new_dist;
                pq.push({distt[v],v});
            } 
        }
    }
    if(dists[t]<=k)
    {
        cout << n*(n-1)/2 << '\n';
        return;
    }
    sort(all(distt));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==s)
        {
            continue;
        }
        int lb=lower_bound(all(distt),k-l-dists[i])-distt.begin();
        ans+=lb;
    }
    cout << ans << '\n';
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