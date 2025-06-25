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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first;
        a[i].second=i;
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    int ub=0;
    int tmp_m=m;
    map<int,int> mp;
    int r=n-1;
    for(int ubb=ub;ubb<n and m>0;m--,ubb++)
    {
        mp[a[r].second]=b[ubb];
        r--;
        ub++;
    }
    int cnt=0;
    int l=0;
    // debug(ub)
    for(int i=ub;i<n;i++)
    {
        mp[a[l].second]=b[i];
        l++;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        ans[i]=mp[i];
    }
    for(int i=0;i<n;i++)
    {
        // debug(a[i].first)
        // debug(mp[a[i].second])
        if(a[i].first>mp[a[i].second])
        {
            cnt++;
        }
    }
    // debug(cnt)
    if(cnt!=tmp_m)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for(auto i:ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
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
// 2 3 4
// 1 2 4
// 2 3 4
// 2 1 4