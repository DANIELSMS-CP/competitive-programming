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
    int n,m,k;
    cin >> n >> m >> k;
    string s="";
    int init_n=n,init_m=m;
    if(n<m)
    {
        swap(n,m);
    }
    if(n<k)
    {
        cout << "-1\n";
        return;
    }
    for(int i=0;i<k;i++)
    {
        s+='0';
        n--;
    }
    int alter=0,balance=k;
    for(int i=0;i<init_n+init_m-k;i++)
    {
        if(alter%2==0)
        {
            if(m>0)
            {
                s+='1';
                m--;
                balance--;
            }
            else if(n>0)
            {
                s+='0';
                n--;
                balance++;
            }
        }
        else
        {
            if(n>0)
            {
                s+='0';
                n--;
                balance++;
            }
            else if(m>0)
            {
                s+='1';
                m--;
                balance--;
            }
        }
        alter++;
        // debug(n+m)
        // debug(s)
    }
    if(balance>k)
    {
        cout << "-1\n";
    }
    else
    {
        for(int i=0;i<sz(s);i++)
        {
            if(init_n<init_m)
            {
                cout << (char)('0'+(s[i]+1)%2);
            }
            else
            {
                cout << s[i];
            }
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