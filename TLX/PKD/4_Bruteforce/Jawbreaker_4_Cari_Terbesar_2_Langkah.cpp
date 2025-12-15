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

int n,m;
vector<vector<int>> vis(30,vector<int>(30,0));
vector<vector<char>> a(30,vector<char>(30));
vector<vector<int>> remove_type_1(30,vector<int>(30,0)),remove_type_2(30,vector<int>(30,0));
int ans,cnt;
int ans_x,ans_y;
void func(int ix,int iy,int type)
{
    char cur=a[ix][iy];
    auto dfs=[&](int x,int y,auto dfs)->void
    {
        vis[x][y]=1;
        if(type==1)
        {
            remove_type_1[x][y]=1;
        }
        else
        {
            remove_type_2[x][y]=1;
        }
        cnt++;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m and not vis[x+dx[i]][y+dy[i]] and a[x][y]==a[x+dx[i]][y+dy[i]])
            {
                dfs(x+dx[i],y+dy[i],dfs);
            }
        }
    };
    auto dfs2=[&](int x,int y,auto dfs2)->void
    {
        a[x][y]='.';
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m and not vis[x+dx[i]][y+dy[i]] and cur==a[x+dx[i]][y+dy[i]])
            {
                a[x+dx[i]][y+dy[i]]='.';
                dfs2(x+dx[i],y+dy[i],dfs2);
            }
        }
    };
    dfs(ix,iy,dfs);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
    }
    dfs2(ix,iy,dfs2);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i+1<n and a[i+1][j]=='.' and a[i][j]!='.')
            {
                int p=i+1;
                while(p<n and a[p][j]=='.' and a[p-1][j]!='.')
                {
                    swap(a[p][j],a[p-1][j]);
                    p++;
                }
            }
        }
    }
    ans+=cnt*(cnt-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
    }
}
void solve()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    auto copy_a=a;
    int final_ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=0;
            cnt=0;
            a=copy_a;
            if(a[i][j]!='.' and not remove_type_1[i][j])
            {
                func(i,j,1);
                auto copycopya=a;
                int ans2=ans;
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        remove_type_2[k][l]=0;
                    }
                }
                if(ans==0)
                {
                    continue;
                }
                final_ans=max(final_ans,ans);
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        cnt=0;
                        ans=ans2;
                        a=copycopya;
                        if(a[k][l]!='.' and not remove_type_2[k][l])
                        {
                            func(k,l,2);
                            final_ans=max(final_ans,ans);
                        }
                    }
                }
            }
        }
    }
    cout << final_ans << '\n';
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