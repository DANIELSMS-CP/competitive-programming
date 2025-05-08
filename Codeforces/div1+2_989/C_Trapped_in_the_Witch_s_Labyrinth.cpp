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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<vector<int>> gans(n,vector<int>(m,1));
    int cnt=0;
    auto dfs=[&](int row,int col,auto &&dfs)->bool
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            if(dir[i]==grid[row][col])
            {
                if(row+dx[i]<0 or row+dx[i]>=n or col+dy[i]<0 or col+dy[i]>=m)
                {
                    return (gans[row][col]=1);
                }
                else
                {
                    if(not vis[row+dx[i]][col+dy[i]] and grid[row+dx[i]][col+dy[i]]!='?')
                    {
                        return (gans[row][col]=dfs(row+dx[i],col+dy[i],dfs));
                    }
                    else
                    {
                        return (gans[row][col]=0);
                    }
                }
            }
            else if(grid[row][col]=='?')
            {
                if(row+dx[i]>=0 and row+dx[i]<n and col+dy[i]>=0 and col+dy[i]<m)
                {
                    gans[row][col]=0;
                }
                if(i==4)
                {
                    return 0;
                }
            }
        }
    };
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(not vis[i][j])
            {
                dfs(i,j,dfs);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(not gans[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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