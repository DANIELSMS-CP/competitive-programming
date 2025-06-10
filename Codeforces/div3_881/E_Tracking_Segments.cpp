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
    vector<pair<int,int>> vp(m);
    for(int i=0;i<m;i++)
    {
        cin >> vp[i].first >> vp[i].second;
        vp[i].first--,vp[i].second--;
    }
    int q;
    cin >> q;
    vector<int> p(q);
    for(int i=0;i<q;i++)
    {
        cin >> p[i];
    }
    int l=0,r=q-1,ans=q;
    while(l<=r)
    {
        int mid=(l+r)/2;
        vector<int> a(n,0);
        for(int i=0;i<=mid;i++)
        {
            a[p[i]-1]=1;
        }
        vector<int> pref(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pref[i]=a[i];
            }
            else
            {
                pref[i]=pref[i-1]+a[i];
            }
        }
        bool found=0;
        for(int i=0;i<m;i++)
        {
            int sum=pref[vp[i].second];
            if(vp[i].first>0)
            {
                sum-=pref[vp[i].first-1];
            }
            if(sum>vp[i].second-vp[i].first+1-sum)
            {
                found=1;
            }
        }
        if(found)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << (ans==q?-1:ans+1) << '\n';
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