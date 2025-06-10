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

bool cap(char a)
{
    return 'A'<=a and a<='Z';
}
void solve()
{
    string s;
    cin >> s;
    int n=sz(s);
    string big="",small="";
    vector<int> pbig,psmall;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='b' and s[i]!='B')
        {
            if(cap(s[i]))
            {
                big+=s[i];
                pbig.push_back(i);
            }
            else
            {
                small+=s[i];
                psmall.push_back(i);
            }
        }
        else
        {
            if(cap(s[i]))
            {
                if(not big.empty())
                {
                    big.pop_back();
                    pbig.pop_back();
                }
            }
            else
            {
                if(not small.empty())
                {
                    small.pop_back();
                    psmall.pop_back();
                }
            }
        }   
    }
    int l1=0,l2=0;
    while(l1<sz(big) and l2<sz(small))
    {
        if(pbig[l1]<psmall[l2])
        {
            cout << big[l1];
            l1++;
        }
        else
        {
            cout << small[l2];
            l2++;
        }
    }
    while(l1<sz(big))
    {
        cout << big[l1];
        l1++;
    }
    while(l2<sz(small))
    {
        cout << small[l2];
        l2++;
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