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
    vector<vector<char>> s(2,vector<char>(n+5));
    vector<vector<int>> a(2,vector<int>(n+5));
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> s[i][j];
            a[i][j]=(s[i][j]=='A');
        }
    }
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cerr << a[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }
    // dp(i,j) = number of filled i with status j
    // j=0 means that noone is ahead
    // j=1 means that top one is ahead
    // j=2 is the mirror of j=1
    vector<vector<int>> dp(n+5,vector<int>(4,LLONG_MIN));
    /*
        base case:
        dp[0][0]=0
        dp[0][1]=LLONG_MIN (impossible)
        dp[0][2]=LLONG_MIN (impossible)
        dp[1][0]=LLONG_MIN (impossible)
    */
    dp[0][0]=0;
    dp[0][1]=LLONG_MIN;
    dp[0][2]=LLONG_MIN; 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                if(i>=3)
                {
                    int addworth=0;
                    addworth+=(a[0][i-2]+a[0][i-1]+a[0][i]>=2);
                    addworth+=(a[1][i-2]+a[1][i-1]+a[1][i]>=2);
                    dp[i][j]=max(dp[i][j],dp[i-3][j]+addworth);
                }
                /*
                    this can also be achieved when we make
                    oo
                     o
                    on a dp[i-2][2]

                    or

                     o
                    oo
                    on a dp[i-2][1]
                */
                if(i>=2)
                {
                    dp[i][j]=max(dp[i][j],dp[i-2][2]+(a[0][i]+a[1][i]+a[0][i-1]>=2));
                    dp[i][j]=max(dp[i][j],dp[i-2][1]+(a[0][i]+a[1][i]+a[1][i-1]>=2));
                }
            }
            else if(j==1)
            {
                if(i>=3)
                {
                    /*
                        ooxx
                        ooox
                    */
                    int addworth=0;
                    addworth+=(a[1][i-2]+a[1][i-1]+a[1][i]>=2);
                    addworth+=(a[0][i-1]+a[0][i]+a[0][i+1]>=2);
                    dp[i][j]=max(dp[i][j],dp[i-3][j]+addworth);
                }
                // come from something flat
                if(i>=1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][0]+(a[0][i+1]+a[0][i]+a[1][i]>=2));
                }
            }
            else
            {
                if(i>=3)
                {
                    /*
                        ooox
                        ooxx
                    */
                    int addworth=0;
                    addworth+=(a[0][i-2]+a[0][i-1]+a[0][i]>=2);
                    addworth+=(a[1][i-1]+a[1][i]+a[1][i+1]>=2);
                    dp[i][j]=max(dp[i][j],dp[i-3][j]+addworth);
                }
                // come from something flat
                if(i>=1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][0]+(a[1][i+1]+a[1][i]+a[0][i]>=2));
                }
            }
        }
    }
    
    cout << dp[n][0]<< '\n';
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