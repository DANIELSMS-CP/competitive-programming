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

struct event
{
    int p;
    bool end;
    int l,r;
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> x(n),y(n);
    vector<event> events;
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        events.push_back({x[i],false,x[i],y[i]});
        events.push_back({y[i],true,x[i],y[i]});
    }
    sort(all(events),
    [](const event &a,const event &b)
        {
            if(a.p!=b.p)
            {
                return a.p<b.p;
            }
            return (not a.end and b.end);
        }
    );
    int ans=0,cnt=0,minleft=0,minright=0;
    for(auto ev:events)
    {
        if(ev.end)
        {
            cnt--;
            if(ev.l==1)
            {
                minleft--;
            }
            if(ev.r==m)
            {
                minright--;
            }
        }
        else
        {
            cnt++;
            if(ev.l==1)
            {
                minleft++;
            }
            if(ev.r==m)
            {
                minright++;
            }
        }
        ans=max(ans,cnt-min(minleft,minright));
    }
    cout << ans << '\n';
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