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
    int n,w;
    cin >> n >> w;
    swap(n,w);
    vector<int> weight(n+1),value(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> weight[i] >> value[i];
    }
    // define the dp for this problem
    // dp(i,j) = max value for item i and weight j
    // base case = trivial case (easy)
    // dp[0][j] = 0
    // dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
    // dp[n][w] 
    map<pair<int,int>,pair<int,int>> mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            mp[{i,j}]={0LL,0LL};
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=weight[i])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i]]+value[i]);
                mp[{i,j}]={i-1,j-weight[i]};
            }
        }
    }
    // cout << dp[n][w] << '\n';
    int best=dp[n][w];
    int minW=0;
    for(int j=0;j<=w;j++){
        if(dp[n][j]==best){
            minW=j;
            break;
        }
    }
    // push dp
    vector<vector<int>> dp2(n+5,vector<int>(minW+1,0));
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=minW;j++)
        {
            dp2[i][j]=dp2[i+1][j];
            if(j>=weight[i])
            {
                dp2[i][j]=max(dp2[i][j],dp2[i+1][j-weight[i]]+value[i]);
            }
        }
    }
    vector<int> ans;
    int remW=minW,remV=best,cur=1;
    while(remV>0)
    {
        for(int i=cur;i<=n;i++)
        {
            if(weight[i]<=remW and value[i]+dp2[i+1][remW-weight[i]]==remV)
            {
                ans.push_back(i);
                remW-=weight[i];
                remV-=value[i];
                cur=i+1;
                break;
            }
        }
    }
    for(auto i:ans)
    {
        cout << i << '\n';
    }
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