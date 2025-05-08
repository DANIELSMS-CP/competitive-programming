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
    vector<int> a(n+1,0),b(m+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
    vector<int> suf(m+1,0);
    for(int i=m;i>=0;i--)
    {
        if(i==m)
        {
            suf[i]=b[i];
        }
        else
        {
            suf[i]=suf[i+1]+b[i];
        }
    }
    sort(all(a));
    sort(all(b));
    int p=0;
    for(int i=n;i>=1;i--)
    {
        p=lower_bound(all(b),a[i])-b.begin();
        if(p>1)
        {
            cout << "-1\n";
            return;
        }
    }
    if(a[n]<b[1] and n==1)
    {
        cout << "-1\n";
        return;
    }
    if(a[1]>b[1])
    {
        cout << "-1\n";
    }
    int ans=0;
    p=lower_bound(all(b),a[n])-b.begin();
    ans+=suf[p];
    for(int i=1;i<n;i++)
    {
        if(i==n-1 and a[n]!=b[1])
        {
            ans+=a[i]*(m-1);
            ans+=a[n]*p;
        }
        else
        {
            ans+=a[i]*m;
        }
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