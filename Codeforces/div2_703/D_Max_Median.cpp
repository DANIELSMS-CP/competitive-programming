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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    auto binser=[&](int mid)
    {
        vector<int> pref(n+1,0);
        pair<int,int> p={1e9,-1e9};
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1];
            if(a[i]>=mid)
            {
                pref[i]++;
            }
            else
            {
                pref[i]--;
            }
            if(i-k>=0)
            {
                p=min(p,make_pair(pref[i-k],i-k));
            }
            if(pref[i]>p.first)
            {
                return make_pair(p.second+1,i);
            }
        }
        return make_pair(-1LL,-1LL);
    };
    int l=1,r=1e9,ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(binser(mid).first!=-1)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
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