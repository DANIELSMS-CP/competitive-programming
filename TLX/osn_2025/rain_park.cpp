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

struct Int 
{
    int u,v,w,z;
};
struct Int2
{
    int u,w,z;
};
class Compare
{
    public:
    bool operator()(Int2 a,Int2 b)
    {
        if(a.w!=b.w)
        {
            return a.w>b.w;
        }
    }
};
struct node
{
    int s,e,m;
    int val;
    node *left,*right;
    node(int ss,int ee,vector<int> &a)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        if(s==e)
        {
            val=a[e];
            return;
        }
        left=new node(s,m,a);
        right=new node(m+1,e,a);
        val=min(left->val,right->val); // !!
    }
    void upd(int p,int v)
    {
        if(s==e)
        {
            val=v; // !!
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
        val=min(left->val,right->val); // !!
    }
    int qry(int l,int r)
    {
        if(l>e or r<s)
        {
            return LLONG_MAX/20; // !!
        }
        if(l<=s and e<=r)
        {
            return val;
        }
        return min(left->qry(l,r),right->qry(l,r)); // !!
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<Int> a(m);
    vector<vector<Int2>> adjlist(n+1);
    for(int i=0;i<m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w >> a[i].z;
        adjlist[a[i].u].push_back({a[i].v,a[i].w,a[i].z});
        adjlist[a[i].v].push_back({a[i].u,a[i].w,a[i].z});
    }
    vector<bool> vis(n+1,0);
    vector<int> ff;
    auto dfs=[&](int u,auto &dfs)->void
    {
        vis[u]=1;
        for(auto i:adjlist[u])
        {
            if(i.z==2 and not vis[i.u])
            {
                ff.push_back(i.u);
                dfs(i.u,dfs);
            }
        }  
    };
    dfs(n,dfs);
    priority_queue<Int2,vector<Int2>,Compare> pq;
    int start=1;
    vector<int> dist(n+1,LLONG_MAX/20);
    dist[start]=0;
    pq.push({start,0,1});
    while(not pq.empty())
    {
        auto topz=pq.top();
        pq.pop();
        int node=topz.u,weight=topz.w,type=topz.z;
        if(dist[node]<weight)
        {
            continue;
        }
        for(auto i:adjlist[node])
        {
            int new_dist=dist[node]+i.w;
            if(new_dist<dist[i.u]) // assume i.second is node in the adjlist
            {
                dist[i.u]=new_dist;
                pq.push({i.u,dist[i.u],i.z});
            } 
        }
    }
    start=n;
    vector<int> dist2(n+1,LLONG_MAX/20);
    dist2[start]=0;
    pq.push({start,0,2});
    while(not pq.empty())
    {
        auto topz=pq.top();
        pq.pop();
        int node=topz.u,weight=topz.w,type=topz.z;
        if(dist2[node]<weight or type==1)
        {
            continue;
        }
        for(auto i:adjlist[node])
        {
            if(i.z==1)
            {
                continue;
            }
            int new_dist=dist2[node]+i.w;
            if(new_dist<dist2[i.u]) // assume i.second is node in the adjlist
            {
                dist2[i.u]=new_dist;
                pq.push({i.u,dist2[i.u],i.z});
            } 
        }
    }
    // dist[i] from 1 dist2[i] from n
    vector<pair<int,int>> avail;
    vector<int> markmark(n+1,0);
    for(auto i:ff)
    {
        avail.push_back({dist[i],i});
        markmark[i]=1;
    }
    avail.push_back({dist[n],n});
    sort(all(avail));
    vector<int> minz;
    for(auto i:avail)
    {
        if(i.second==n)
        {
            minz.push_back(dist[i.second]);
        }
        minz.push_back(dist[i.second]+dist2[i.second]);
    }
    node segtree(0LL,(int)minz.size()-1,minz);
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        int lb=upper_bound(all(avail),make_pair(t,LLONG_MAX))-avail.begin()-1;
        if(lb<0)
        {
            cout << "-1\n";
        }
        else
        {
            int qq=segtree.qry(0LL,lb);
            cout << qq << '\n';
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