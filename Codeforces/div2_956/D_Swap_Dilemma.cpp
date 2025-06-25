//and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
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
const int MOD=1e9+7;
const int maxn=2e5+5;
const double eps=1e-9;
 
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
//Mods
int add(int a, int b) 
{
    if((a+=b)>=MOD)
    {
        a-=MOD;
    }
    return a;
}
int sub(int a, int b) 
{
  if((a-=b)<0)
  {
        a+=MOD;
  }
  return a;
}
int mul(int a,int b) 
{
    int ret=(a%MOD*b%MOD)%MOD;
    if(ret<0)
    {
        ret+=MOD;
    }
    return ret;
}

template<typename T = int>
struct BIT{
    vector<T> bit;

    BIT(int n = 0){
        bit = vector<T>(n+1);
    }
    
    static void merge(T& a, T b){
        a+=b;
    }

    void update(int id, T x){
        id++;
        while(id < bit.size()){
            merge(bit[id],x);
            id+=id&-id;
        }
    }

    T query(int id){
        id++;
        T ret = T();
        while(id){
            merge(ret,bit[id]);
            id-=id&-id;
        }
        return ret;
    }
};
BIT<int> ab((int)1e6+5),bb((int)1e6+5);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+5),b(n+5);
    map<int,int> cnt;
    int mx=0,mx2=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        mx2=max(mx2,b[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(cnt[b[i]]==0)
        {
            cout << "NO\n";
            return;
        }
        cnt[b[i]]--;
    }
    int inv1=0,inv2=0;
    for(int i=0;i<n;i++)
    {
        inv1+=ab.query((int)mx)-ab.query(a[i]);
        ab.update(a[i],1);
    }
    for(int i=0;i<n;i++)
    {
        inv2+=bb.query((int)mx2)-bb.query(b[i]);
        bb.update(b[i],1);
    }
    for(int i=0;i<n;i++)
    {
        ab.update(a[i],-1);
    }
    for(int i=0;i<n;i++)
    {
        bb.update(b[i],-1);
    }
    cout << (inv1%2==inv2%2?"YES\n":"NO\n");
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