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

int kadane(vector<int> &a)
{
    int mx=0,sum=0,mn=0;
    for(int i=0;i<sz(a);i++)
    {
        sum+=a[i];
        mx=max(mx,sum);
        sum=max(sum,0LL);
    }
    return mx;
}
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    string s;
    cin >> s;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(s[i]=='0')
        {
            pos=i;
            a[i]=-1e12;
        }
    }
    int calc=kadane(a);
    if(calc>k or (calc!=k and pos==-1))
    {
        cout << "No\n";
        return;
    }
    if(calc==k)
    {
        cout << "Yes\n";
        for(int i=0;i<n;i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int l=-1e12,r=1e12+1,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        a[pos]=mid;
        calc=kadane(a);
        if(calc<=k)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    a[pos]=ans;
    cout << "Yes\n";
    for(int i=0;i<n;i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
signed main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
