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
    int a,b,c;
    cin >> a >> b >> c;
    int a1,a2,a3,a4,a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    a-=a1;
    b-=a2;
    c-=a3;
    if(a<0 or b<0 or c<0)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        a1=0,a2=0,a3=0;
    }
    if(a4>a)
    {
        a4-=a;
        a=0;
    }
    else
    {
        a-=a4;
        a4=0;
    }
    if(a4>c)
    {
        a4-=c;
        c=0;
    }
    else
    {
        c-=a4;
        a4=0;
    }
    if(a5>b)
    {
        a5-=b;
        b=0;
    }
    else
    {
        b-=a5;
        a5=0;
    }
    if(a5>c)
    {
        a5-=c;
        c=0;
    }
    else
    {
        c-=a5;
        a5=0;
    }
    if(not(a1 or a2 or a3 or a4 or a5))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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