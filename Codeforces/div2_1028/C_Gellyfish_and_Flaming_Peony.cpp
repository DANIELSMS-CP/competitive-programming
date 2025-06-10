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

int g[5005][5005];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int m=0,k=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        k=g[k][a[i]];
    }
    vector<int> dp(5005);
    for(int i=0;i<=5000;i++)
    {
        dp[i]=63;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]/=k;
        if(m<a[i])
        {
            m=a[i];
        }
        dp[a[i]]=0;
    }
    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            int x=a[j];
            if(dp[g[i][x]]>dp[i]+1)
            {
                dp[g[i][x]]=dp[i]+1;
            }
        }
    }
    int ans=max(dp[1]-1,0LL);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    fastio();
    for(int i=0;i<=5000;i++)
    {
        g[0][i]=i;
        g[i][0]=i;
        g[i][i]=i;
    }
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<i;j++)
        {
            g[i][j]=g[j][i]=g[j][i%j];
        }
    }
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}