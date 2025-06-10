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
    int tmp_n=n;
    map<int,int> mp;
    int cnt=1;
    for(int i=2;i*i<=tmp_n;i++)
    {  
        if(n%i==0)
        {
            cnt*=i;
        }
        while(n>1 and n%i==0)
        {
            mp[i]++;
            n/=i;
        }
    }   
    if(n>1)
    {
        mp[n]++;
        cnt*=n;
    }
    int ans=0;
    bool found=1;
    while(found)
    {
        found=0;
        ans+=cnt;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>0)
            {
                it->second--;
                found=1;
            }
            if(it->second==0)
            {
                cnt/=it->first;
                it->second--;
            }
        }
    }
    cout << ans-1 << '\n';
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
// 2^2*5^2