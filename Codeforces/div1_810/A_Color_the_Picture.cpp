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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for(int i=0;i<k;i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    bool flag=1;
    int cnt=0;
    bool more2=0;
    for(int i=0;i<k;i++)
    {
        if(cnt>=m)
        {
            break;
        }
        int take=a[i]/n;
        if(take<2)
        {
            continue;
        }
        if(cnt+take>m)
        {
            if(more2 or take>2)
            {
                cnt=m;
                break;
            }
            else
            {
                continue;
            }
        }
        cnt+=take;
        if(a[i]/n>2)
        {
            more2=1;
        }
    }
    if(cnt<m)
    {
        flag=0;
    }
    if(flag)
    {
        cout << "Yes\n";
        return;
    }
    flag=1;
    cnt=0;
    more2=0;
    for(int i=0;i<k;i++)
    {
        if(cnt>=n)
        {
            break;
        }
        int take=a[i]/m;
        if(take<2)
        {
            continue;
        }
        if(cnt+take>n)
        {
            if(more2 or take>2)
            {
                cnt=n;
                break;
            }
            else
            {
                continue;
            }
        }
        cnt+=take;
        if(take>2)
        {
            more2=1;
        }
    }
    if(cnt<n)
    {
        flag=0;
    }
    if(flag)
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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