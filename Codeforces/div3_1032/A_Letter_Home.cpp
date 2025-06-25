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
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int ans=0;
    int pos=s;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]<=s and a[i]>=s)
        {
            int l=0,r=0;
            for(int j=1;j<i;j++)
            {
                l+=a[j]-a[j-1];
            }
            for(int j=i+1;j<n;j++)
            {
                r+=a[j]-a[j-1];
            }
            l+=s-a[i-1];
            r+=a[i]-s;
            cout << min(2*r,2*l)+max(r,l) << '\n';
            return;
        }
    }
    if(s<=a[0])
    {
        for(int i=0;i<n;i++)
        {
            ans+=a[i]-pos;
            pos=a[i];
        }
        cout << ans << '\n';
    }
    else if(s>a[n-1])
    {
        for(int i=1;i<n;i++)
        {
            ans+=a[i]-a[i-1];
        }
        ans+=s-a[n-1];
        cout << ans << '\n';
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