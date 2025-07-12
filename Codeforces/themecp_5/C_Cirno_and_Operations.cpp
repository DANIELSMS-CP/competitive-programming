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
    vector<int> a(n);
    int sum_i=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum_i+=a[i];
    } 
    if(n==1)
    {
        cout << a[0] << '\n';
        return;
    }
    int sum=sum_i;
    vector<vector<int>> pascal_tri(1,{1});
    while(sz(pascal_tri)<=n)
    {
        if(sz(pascal_tri)==1)
        {
            pascal_tri.push_back({1,1});
        }
        else
        {
            vector<int> new_tri;
            new_tri.push_back(pascal_tri.back()[0]);
            for(int i=1;i<sz(pascal_tri);i++)
            {
                new_tri.push_back(pascal_tri.back()[i]+pascal_tri.back()[i-1]);
            }
            new_tri.push_back(pascal_tri.back().back());
            pascal_tri.push_back(new_tri);
        }
    }
    int f=0;
    while(sz(a)>1)
    {
        debug(sz(a));
        int cnt=0,cnt2=0;
        // for(auto i:a)
        // {
        //     cerr << i << ' ';
        // }
        // cerr << '\n';
        for(auto i:a)
        {
            cnt2+=i;
        }
        for(int i=0;i<sz(a);i++)
        {
            if(i%2)
            {
                cnt+=a[i]*pascal_tri[sz(a)-1][i];
            }
            else
            {
                cnt-=a[i]*pascal_tri[sz(a)-1][i];
            }
        }
        vector<int> new_a;
        for(int i=1;i<sz(a);i++)
        {
            new_a.push_back(a[i]-a[i-1]);
        }
        a=new_a;
        sum=max({sum,cnt,-cnt,cnt2});
        if(f>0)
        {
            sum=max(sum,-cnt2);
        }
        f++;
    }
    cout << sum << '\n';
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