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
    int n,k;
    cin >> n >> k;
    vector<vector<char>> a(n,vector<char>(k));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<char>> ans(n,vector<char>(k,'-'));
    vector<vector<bool>> vis(n,vector<bool>(k));
    char poss[]={'B','W'};
    auto dfs=[&](int r,int c,int stat,auto &&dfs)->void
    {
        ans[r][c]=poss[stat];
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            if(r+dx[i]>=0 and r+dx[i]<n and c+dy[i]>=0 and c+dy[i]<k and not vis[r+dx[i]][c+dy[i]] and a[r+dx[i]][c+dy[i]]!='-')
            {
                dfs(r+dx[i],c+dy[i],(stat+1)%2,dfs);
            }
        }
    };
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(a[i][j]!='-' and not vis[i][j])
            {
                dfs(i,j,0,dfs);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
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
