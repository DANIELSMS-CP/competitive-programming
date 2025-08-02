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

int find_number(int l,int r,int a)
{
    int mx=(r/a)*a;
    int mn=(l+a-1)/a*a;
    if(mx<mn)
    {
        return 0;
    }
    else
    {
        return (mx-mn)/a+1;
    }
}
void solve()
{
    int l,r;
    cin >> l >> r;
    int a1=2,a2=3,a3=5,a4=7,b1=6,b2=10,b3=14,b4=15,b5=21,b6=35,c1=30,c2=42,c3=70,c4=105,d1=210;
    int ans=(r-l+1);
    ans-=find_number(l,r,a1);
    ans-=find_number(l,r,a2);
    ans-=find_number(l,r,a3);
    ans-=find_number(l,r,a4);
    ans+=find_number(l,r,b1);
    ans+=find_number(l,r,b2);
    ans+=find_number(l,r,b3);
    ans+=find_number(l,r,b4);
    ans+=find_number(l,r,b5);
    ans+=find_number(l,r,b6);
    ans-=find_number(l,r,c1);
    ans-=find_number(l,r,c2);
    ans-=find_number(l,r,c3);
    ans-=find_number(l,r,c4);
    ans+=find_number(l,r,d1);
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