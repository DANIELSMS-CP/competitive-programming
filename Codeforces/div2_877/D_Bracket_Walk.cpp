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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> open,close;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            if(s[i]=='(')
            {
                open.insert(i);
            }
            else
            {
                close.insert(i);
            }
        }
    }
    while(q--)
    {
        int p;
        cin >> p;
        if(n%2)
        {
            cout << "NO\n";
            continue;
        }
        p--;
        if(open.find(p)!=open.end())
        {
            open.erase(p);
        }
        else if(close.find(p)!=close.end())
        {
            close.erase(p);
        }
        if(open.find(p+1)!=open.end())
        {
            open.erase(p+1);
        }
        else if(close.find(p+1)!=close.end())
        {
            close.erase(p+1);
        }
        if(s[p]=='(')
        {
            s[p]=')';
        }
        else
        {
            s[p]='(';
        }
        if(p>0 and s[p]==s[p-1])
        {
            if(s[p]=='(')
            {
                open.insert(p);
            }
            else
            {
                close.insert(p);
            }
        }
        if(p<n-1 and s[p]==s[p+1])
        {
            if(s[p+1]=='(')
            {
                open.insert(p+1);
            }
            else
            {
                close.insert(p+1);
            }
        }
        if(s[0]==')' or s[n-1]=='(')
        {
            cout << "NO\n";
        }
        else if(open.empty() and close.empty())
        {
            cout << "YES\n";
        }
        else if((open.empty() and not close.empty()) or (close.empty() and not open.empty()))
        {
            cout << "NO\n";
        }
        else if(*open.begin()>*close.begin() or *open.rbegin()>*close.rbegin())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
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