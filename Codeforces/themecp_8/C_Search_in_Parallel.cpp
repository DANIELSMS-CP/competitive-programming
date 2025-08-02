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
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    vector<pair<int,int>> r(n);
    for(int i=0;i<n;i++)
    {
        cin >> r[i].first;
        r[i].second=(i+1);
    }
    sort(all(r));
    reverse(all(r));
    vector<int> v1,v2;
    if(s1<s2)
    {
        for(int i=0;i<n;i++)
        {
            if(v1.empty())
            {
                v1.push_back(r[i].second);
            }
            else
            {
                if(s1*(sz(v1)+1)<s2*(sz(v2)+1))
                {
                    v1.push_back(r[i].second);
                }
                else
                {
                    v2.push_back(r[i].second);
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(v2.empty())
            {
                v2.push_back(r[i].second);
            }
            else
            {
                if(s1*(sz(v1)+1)<s2*(sz(v2)+1))
                {
                    v1.push_back(r[i].second);
                }
                else
                {
                    v2.push_back(r[i].second);
                }
            }
            // for(auto j:v1)
            // {
            //     cerr << j << ' ';
            // }
            // cerr << '\n';
            // for(auto j:v2)
            // {
            //     cerr << j << ' ';
            // }
            // cerr << '\n';
        }
    }
    cout << sz(v1) << ' ';
    for(auto i:v1)
    {
        cout << i << ' ';
    }
    cout << '\n';
    cout << sz(v2) << ' ';
    for(auto i:v2)
    {
        cout << i << ' ';
    }
    cout << '\n';
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