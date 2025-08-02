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
    if(k%2)
    {
        cout << "No\n";
    }
    else
    {
        int sum=0;
        vector<int> ans;
        for(int i=n;i>=1;i--)
        {
            ans.push_back(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            // cerr << ans[i] << ' ';
            sum+=abs((i+1)-ans[i]);
        }
        // debug(sum)
        if(sum<k)
        {
            cout << "No\n";
            return;
        }
        vector<int> ans2;
        for(int i=0;i<n;i++)
        {
            ans2.push_back(i+1);
        }
        // for(auto j:ans)
        // {
        //     cerr << j << ' ';
        // }
        // cerr << '\n';
        sum=0;
        vector<bool> used(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(sum+2*abs((i+1)-ans[i])<=k and abs((i+1)-ans[i])>0)
            {
                used[ans[i]]=1;
                used[ans2[ans[i]-1]]=1;
                sum+=2*abs((i+1)-ans[i]);
                swap(ans2[ans[i]-1],ans2[i]);
                // for(auto j:ans)
                // {
                //     cerr << j << ' ';
                // }
                // cerr << '\n';
                // cerr << sum << '\n';
                // cerr << i << '\n';
            }
            else
            {
                int diff=(k-sum)/2;
                if(not used[ans2[i]] and not used[ans2[ans2[i]+diff-1]])
                {
                    swap(ans2[ans2[i]+diff-1],ans2[i]);
                    break;
                }
            }
        }
        // debug(sum)
        // int chk=0;
        // for(int i=0;i<n;i++)
        // {
        //     chk+=abs((i+1)-ans2[i]);
        // }
        // assert(chk==k);
        cout << "Yes\n";
        for(auto i:ans2)
        {
            cout << i << ' ';
        }
        cout << '\n';
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