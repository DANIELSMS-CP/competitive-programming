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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    unordered_map<int,int,custom_hash> mp;
    mp[n]=1;
    for(int i=0;i<30;i++)
    {
        for(auto [key,val]:mp)
        {
            if(mp[key]>0)
            {
                if(mp[key/2]>0)
                {
                    mp[key/2]=min(mp[key/2],mp[key]+1);
                }
                else
                {
                    mp[key/2]=mp[key]+1;
                }
                if(mp[(key+1)/2]>0)
                {
                    mp[(key+1)/2]=min(mp[(key+1)/2],mp[key]+1);
                }
                else
                {
                    mp[(key+1)/2]=mp[key]+1;
                }
                i=min(key/2,i);
                if(mp[key]!=m)
                {
                    mp[key]=0;
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();)
        {
            if(it==0)
            {
                mp.erase(it++);
            }
            else
            {
                it++;
            }
        }
    }
    cout << (mp[m]==0?-1:mp[m]-1) << '\n';
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