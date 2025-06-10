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
const int MOD=998244353;
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

int fast_mul(int a,int p)
{
    if(p==0)
    {
        return 1;
    }
    if(p==1)
    {
        return a;
    }
    int pp=fast_mul(a,p/2);
    if(p%2)
    {
        return mul(mul(pp,pp),a);
    }
    else
    {
        return mul(pp,pp);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    priority_queue<pair<int,int>> pqa,pqb;
    for(int i=0;i<n;i++)
    {
        pqa.push({a[i],i});
        pqb.push({b[i],i});
        if(pqa.top().first>pqb.top().first)
        {
            cout << add(fast_mul(2,pqa.top().first),fast_mul(2,b[i-pqa.top().second])) << ' ';
        }
        else if(pqa.top().first<pqb.top().first)
        {
            cout << add(fast_mul(2,pqb.top().first),fast_mul(2,a[i-pqb.top().second])) << ' ';
        }
        else
        {
            if(b[i-pqa.top().second]>a[i-pqb.top().second])
            {
                cout << add(fast_mul(2,pqa.top().first),fast_mul(2,b[i-pqa.top().second])) << ' ';
            }
            else
            {
                cout << add(fast_mul(2,pqb.top().first),fast_mul(2,a[i-pqb.top().second])) << ' ';
            }
        }
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
