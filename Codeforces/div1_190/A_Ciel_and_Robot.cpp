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
const int dx[4]{-1, 0, 1, 0}, dy[4]{0, 1, 0, -1}; 
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

bool same_sign(int a,int b)
{
    return ((a<0 and b<0) or (a>0 and b>0));
}
void solve()
{
    int l,r;
    cin >> l >> r;
    string s;
    cin >> s;
    int n=sz(s);
    int final_l=0,final_r=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(s[i]==dir[j])
            {
                final_r+=dx[j];
                final_l+=dy[j];
                break;
            }
        }
    }
    int cur_l=0,cur_r=0;
    if(cur_l==l and cur_r==r)
    {
        cout << "Yes\n";
        return;
    }
    for(int p=0;p<n;p++)
    {
        for(int j=0;j<4;j++)
        {
            if(s[p]==dir[j])
            {
                cur_r+=dx[j];
                cur_l+=dy[j];
                break;
            }
        }
        int ll=0,rr=1e15;
        while(ll<=rr)
        {
            int mid=(ll+rr)/2;
            if(mid*final_l+cur_l==l and mid*final_r+cur_r==r)
            {
                cout << "Yes\n";
                return;
            }
            else if(abs(mid*final_l+cur_l)<abs(l) and abs(mid*final_r+cur_r)<abs(r))
            {
                ll=mid+1;
            }
            else if(abs(mid*final_l+cur_l)>abs(l) and abs(mid*final_r+cur_r)>abs(r))
            {
                rr=mid-1;
            }
            else
            {
                break;
            }
        }
    }
    cout << "No\n";
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