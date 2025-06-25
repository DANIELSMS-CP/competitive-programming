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
    int n,k;
    cin >> n >> k;
    vector<int> p(n),d(n);
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> d[i];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int s;
        cin >> s;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist=p[j]-p[i];
                if(s>=d[i] and s<=d[j])
                {
                    dist-=(s-p[i]);
                }
                debug(dist)
                if(d[j]==0 or (dist-d[i])%d[j]==0)
                {
                    if((d[i]==0 or ((p[j]-p[i])-d[i])%k==0) and (d[j]==0 or ((p[j]-p[i])-d[j])%k==0))
                    {
                        cerr << i << ' ' << j << '\n';
                        debug(((p[j]-p[i])-d[i]))
                        flag=0;            
                    }
                }
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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