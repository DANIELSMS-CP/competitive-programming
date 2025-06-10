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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    s='0'+s;
    int x0=0,x1=0;
    vector<int> pref1(n+1,0),pref0(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            if(s[i]=='0')
            {
                pref0[1]=a[i];
            }
            else
            {
                pref1[1]=a[i];
            }
        }
        else
        {
            pref0[i]=(pref0[i-1]);
            pref1[i]=(pref1[i-1]);
            if(s[i]=='0')
            {
                pref0[i]=(pref0[i-1]^a[i]);
            }
            else
            {
                pref1[i]=(pref1[i-1]^a[i]);
            }
        }
    }
    x0=pref0[n];
    x1=pref1[n];
    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            int l,r;
            cin >> l >> r;
            x0=(x0^pref0[r]^pref0[l-1]);
            x1=(x1^pref1[r]^pref1[l-1]);
            x0=(x0^pref1[r]^pref1[l-1]);
            x1=(x1^pref0[r]^pref0[l-1]);
        }
        else
        {
            int x;
            cin >> x;
            if(x==0)
            {
                cout << x0 << ' ';
            }
            else
            {
                cout << x1 << ' ';
            }
        }
    }
    cout << '\n';
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