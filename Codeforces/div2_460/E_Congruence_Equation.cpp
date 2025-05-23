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
int MOD=1e9+7;
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

int pw(int a,int p)
{
    if(p==0)
    {
        return 1;
    }
    if(p==1)
    {
        return a;
    }
    int pp=pw(a,p/2);
    if(p%2)
    {
        return mul(mul(pp,pp),a);
    }
    else
    {
        return mul(pp,pp);
    }
}
int inv(int a,int p)
{
    return pw(a,p-2);
}
void solve()
{
    int a,b,p,x;
    cin >> a >> b >> p >> x;
    MOD=p;
    int ans=0;
    for(int i=1;i<=p-1;i++)
    {
        int now=mul(b,inv(pw(a,i),p));
        int first=(p-1)*((i-now+p)%p)+i;
        if(first>x)
        {
            continue;
        }
        ans+=(x-first)/(p*(p-1))+1;
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