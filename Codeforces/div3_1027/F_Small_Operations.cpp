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

int get_ans(int x,int k)
{
    if(x==1)
    {
        return 0;
    }
    vector<int> divs;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            divs.push_back(i);
            divs.push_back(x/i);
        }
    }
    sort(all(divs));
    int n=sz(divs);
    vector<int> dp(n,100);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(divs[i]/divs[j]>k)
            {
                break;
            }
            if(divs[i]%divs[j]==0)
            {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return (dp[n-1]==100?-1:dp[n-1]);
}
void solve()
{
    int x,y,k;
    cin >> x >> y >> k;
    int g=__gcd(x,y);
    x/=g;
    y/=g;
    int ax=get_ans(x,k),ay=get_ans(y,k);
    if(ax==-1 or ay==-1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ax+ay << '\n';
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