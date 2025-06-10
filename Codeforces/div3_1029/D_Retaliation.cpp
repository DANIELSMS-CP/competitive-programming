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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int> reva=a;
    reverse(all(reva));
    if(not is_sorted(all(a)) and not is_sorted(all(reva)))
    {
        cout << "NO\n";
        return;
    }
    if(a[0]>a[n-1])
    {
        a=reva;
    }
    int cnt=0,cnt2=0;
    int diff=a[n-1]-a[0];
    if(diff%(n-1)!=0)
    {
        cout << "NO\n";
        return;
    }
    int off=diff/(n-1);
    int l=0,r=1e9,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid+(mid+off)*n==a[n-1])
        {
            ans=mid;
            break;
        }
        else if(mid+(mid+off)*n<a[n-1])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cnt=ans,cnt2=ans+off;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=cnt2*(i+1)+cnt*(n-i))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
// x+y=5
// x=4 y=1
// // x*n+y=a[n-1];
// // x+y*n=a[0];
// // x*(n-1)-y*(n-1)=a[n-1]-a[0];
// // (n-1)(x-y)=diff 
// // x-y=diff/(n-1)
// x=diff/(n-1)+y 

